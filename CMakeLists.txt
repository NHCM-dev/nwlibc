cmake_minimum_required(VERSION 3.24)
project(nwlibc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT WIN32)
    message(FATAL_ERROR "nwlibc currently targets Windows only")
endif()

add_library(nwlibc_windows OBJECT src/c/platform/windows/windows.cpp)
add_library(nwlibc STATIC
    src/c/string/string.cpp
        lib/c/include/stddef.h
        lib/c/include/internal/__stddef.h
    $<TARGET_OBJECTS:nwlibc_windows>)
add_library(nwlibcxx STATIC
    src/c++/cstddef.cpp
    lib/c++/include/cstddef
    lib/c++/include/cstring)
add_library(nwlibc::nwlibc ALIAS nwlibc)
add_library(nwlibc::c ALIAS nwlibc)
add_library(nwlibc::cxx ALIAS nwlibcxx)

target_include_directories(nwlibc PUBLIC lib/c/include)
target_include_directories(nwlibcxx PUBLIC lib/c++/include)
target_link_libraries(nwlibc PRIVATE kernel32)
target_link_libraries(nwlibcxx PUBLIC nwlibc)
set_target_properties(nwlibc nwlibcxx nwlibc_windows PROPERTIES
    C_STANDARD 17 C_STANDARD_REQUIRED YES C_EXTENSIONS NO
    CXX_STANDARD 23 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

# Disable MSVC runtime checks and exception handling defaults.
if(MSVC)
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

# SDK includes are confined to nwlibc_windows.
foreach(target nwlibc nwlibcxx)
    if(MSVC)
        target_compile_options(${target} PRIVATE /X)
    else()
        target_compile_options(${target} PRIVATE
            -nostdinc $<$<COMPILE_LANGUAGE:CXX>:-nostdinc++> -ffreestanding)
    endif()
endforeach()
target_compile_definitions(nwlibc_windows PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)

foreach(target nwlibc nwlibcxx nwlibc_windows)
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
