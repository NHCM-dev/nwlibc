# Contributing to nwlibc
Since the standard library for every programming language is a very big project, nwlibc is welcome for contributors.

## Setup

For development setup, you need these softwares at least:
* Git
* CMake
* Windows development environment (VS studio)
* C compiling toolchain (MSVC preferred. GCC, Clang optional)

Clone the repository into a directory
```shell
git clone https://github.com/NHCM-dev/nwlibc.git
cd nwlibc
```

Configure and build:

```cmake
cmake -S . -B build
cmake --build build
```

## Coding guidelines

* Windows only implementation
* Use C23 as the basic implementation standard
* Trying to make compatibility for older C standard such as C11
* Give support for C++ and the same time
* Avoid unnecessary dependencies, only WinAPI is accepted
* Put private implementation in internal directory in the includes/implementation directories

## Submitting Changes

1. Fork the repository
2. Add new codes
3. Keep descriptions clear and simple
4. Submit a pull request

## Others

If there are bugs, feel free to report via issues.  
If you want some new features to be added, you can also submit it via issues.  
Thank you for your contributions to nwlibc!