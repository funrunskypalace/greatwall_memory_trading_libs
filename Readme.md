# Introduction

GreatWall-Memory-Trading-Libs(GMT) is a C++ Fast Library for Trading Futures, Stocks, Options and etc. You can do trading and back testing seamlessly by using GMT.

- Pure C++ code
- Mmap for fast flow read/write and data protection.
- Dynamic link libraries for writing trading strategy and market data enhance plugins.
- Back Test and Trade using exactly same code.
- Hundreds of strategy instances can run simultaneously.
- Support both Linux and Windows, x64 and x86 archs.

# Note

Please copy `/target/bin` to `/app_home/bin` each time after git pull.

# Dev Guide

## Windows

Steps:

- Install Visual Stuido 2019.
- Install CMake 3.15 upper.
- Git clone vcpkg from github, get vcpkg.exe, and then add exe path to system variable.
- go to /scripts directory, run x64_2019.bat for VS2019 and x64 environment.
- go to /build directory, got VS2019 sln file.
