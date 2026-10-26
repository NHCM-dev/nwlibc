cmake_minimum_required(VERSION 3.24)
project(nwlibc VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT WIN32)
    message(FATAL_ERROR "nwlibc currently targets Windows only")
endif()
add_library(nwlibc_windows OBJECT src/platform/windows/windows.cpp)
add_library(nwlibc STATIC
    src/string.cpp
    include/string.h
    include/stddef.h
    internal/__stddef.h
    $<TARGET_OBJECTS:nwlibc_windows>)
add_library(nwlibc::nwlibc ALIAS nwlibc)
target_include_directories(nwlibc PUBLIC include)
target_include_directories(nwlibc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(nwlibc PRIVATE kernel32)
set_target_properties(nwlibc nwlibc_windows PROPERTIES
    CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

# CMake's default MSVC Debug runtime checks require the host CRT.
if(MSVC)
    foreach(config DEBUG RELEASE RELWITHDEBINFO MINSIZEREL)
        string(REGEX REPLACE "/RTC[1su]+" "" CMAKE_CXX_FLAGS_${config}
            "${CMAKE_CXX_FLAGS_${config}}")
    endforeach()
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    target_compile_options(nwlibc PRIVATE /X)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(nwlibc PRIVATE -nostdinc -nostdinc++ -ffreestanding)
else()
    message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

# Keep SDK headers confined to the Windows object library.
target_compile_definitions(nwlibc_windows PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
foreach(target nwlibc nwlibc_windows)
    if(MSVC)
        target_compile_options(${target} PRIVATE
            /W4 /WX /GS- /Zl /Oi- /GR- /EHs-c- /Zc:threadSafeInit- /Zc:__cplusplus)
    else()
        target_compile_options(${target} PRIVATE
            -Wall -Wextra -Wpedantic -Werror
            -fno-builtin -fno-stack-protector
            -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit)
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            target_compile_options(${target} PRIVATE -fno-tree-loop-distribute-patterns)
        endif()
    endif()
endforeach()
