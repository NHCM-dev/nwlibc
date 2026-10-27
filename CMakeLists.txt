cmake_minimum_required(VERSION 3.24)
project(nwlibc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT WIN32)
    message(FATAL_ERROR "nwlibc currently targets Windows only")
endif()

add_library(nwlibc_winapi INTERFACE)
add_library(nwlibc::winapi ALIAS nwlibc_winapi)
target_compile_definitions(nwlibc_winapi INTERFACE WIN32_LEAN_AND_MEAN NOMINMAX)
target_link_libraries(nwlibc_winapi INTERFACE kernel32 user32)
if(MSVC)
    # SDK stralign.h needs wide CRT declarations absent from our partial string.h.
    target_compile_options(nwlibc_winapi INTERFACE
        "/FI${CMAKE_CURRENT_SOURCE_DIR}/lib/c/include/internal/__windows_sdk.h")
endif()

add_library(nwlibc STATIC
        src/c/errno.c
        lib/c/include/errno.h
        lib/c/include/internal/__errno.h
        src/c/string.c
        src/c/stdlib.c
        lib/c/include/stddef.h
        lib/c/include/internal/__stddef.h
        lib/c/include/string.h
        lib/c/include/internal/__cdefs.h
        lib/c/include/internal/__stdlib.h
        src/c/internal/__stdlib.c
        src/c/stdio.c
        lib/c/include/internal/__stdio.h
        src/c/internal/__stdio.c
        lib/c/include/stdbool.h
        lib/c/include/ctype.h
        src/c/internal/__ctype.c
        lib/c/include/internal/__ctype.h
        src/c/ctype.c
        lib/c/include/stdalign.h
        lib/c/include/stdnoreturn.h)
add_library(nwlibcxx STATIC
    src/c++/empty.cpp
        lib/c++/include/cstddef)
add_library(nwlibc::nwlibc ALIAS nwlibc)
add_library(nwlibc::c ALIAS nwlibc)
add_library(nwlibc::cxx ALIAS nwlibcxx)

target_include_directories(nwlibc PUBLIC lib/c/include)
target_include_directories(nwlibcxx PUBLIC lib/c++/include)
target_link_libraries(nwlibc PUBLIC nwlibc_winapi)
target_link_libraries(nwlibcxx PUBLIC nwlibc)

add_executable(nwlibc_example test/main.c)
target_link_libraries(nwlibc_example PRIVATE nwlibc::cxx)

set_target_properties(nwlibc nwlibcxx nwlibc_example PROPERTIES
    C_STANDARD 23 C_STANDARD_REQUIRED YES C_EXTENSIONS NO
    CXX_STANDARD 23 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

# Disable MSVC runtime checks and exception handling defaults.
if(MSVC)
    # MSVC currently provides C17 mode, while GNU/Clang use C23 above.
    set_target_properties(nwlibc nwlibc_example PROPERTIES C_STANDARD 17)
    foreach(language C CXX)
        foreach(config DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
            string(REGEX REPLACE "/RTC[1su]+" "" CMAKE_${language}_FLAGS_${config}
                "${CMAKE_${language}_FLAGS_${config}}")
        endforeach()
    endforeach()
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif(NOT CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# SDK and C runtime support headers are available to all sources.
# Keep the toolchain's C++ standard library headers disabled on GNU/Clang.
foreach(target nwlibc nwlibcxx nwlibc_example)
    if(NOT MSVC)
        target_compile_options(${target} PRIVATE
            $<$<COMPILE_LANGUAGE:CXX>:-nostdinc++>)
    endif()
endforeach()

foreach(target nwlibc nwlibcxx)
    if(MSVC)
        target_compile_options(${target} PRIVATE
            /W4 /WX /GS- /Zl /Oi-
            "$<$<COMPILE_LANGUAGE:CXX>:/GR-;/EHs-c-;/Zc:threadSafeInit-;/Zc:__cplusplus>")
    else()
        target_compile_options(${target} PRIVATE
            -Wall -Wextra -Wpedantic -Werror -fno-builtin -fno-stack-protector
            "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions;-fno-rtti;-fno-threadsafe-statics;-fno-use-cxa-atexit>")
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            target_compile_options(${target} PRIVATE -fno-tree-loop-distribute-patterns)
        endif()
    endif()
endforeach()
