@echo off
set VCPKG_VER=x64-windows
set VCPKG_ROOT=e:/opensource/vcpkg

set "var=%cd%"
cd %VCPKG_ROOT% 
vcpkg integrate install
rem vcpkg install c-ares:x64-windows
rem vcpkg install tbb:x64-windows
rem vcpkg install zlib:x64-windows
rem vcpkg install xxhash:x64-windows
vcpkg install abseil:x64-windows
rem vcpkg install nng:x64-windows
rem do not !!! vcpkg install libevent:x64-windows
rem vcpkg install yaml-cpp:x64-windows
rem vcpkg install tclap:x64-windows
vcpkg install spdlog:x64-windows
vcpkg install nlohmann-json:x64-windows
vcpkg install fmt:x64-windows
rem vcpkg install hdf5:x64-windows
cd %var%
cd ..
copy /Y CMakeLists-template-win64.txt CMakeLists.txt
mkdir target\bin
mkdir target\lib
mkdir target\config
mkdir target\instance_config
mkdir app_home\bin
mkdir app_home\config
mkdir app_home\instance_config
mkdir build\x64windows
cd build\x64windows
rem del CMakeCache.txt
rem -Dgtest_force_shared_crt=${GTEST_FORCE_SHARED_CRT} 
cmake ../.. -G "Visual Studio 16 2019" -Ax64 -T v142,host=x64 -DPreferredToolArchitecture=x64
cd ../../scripts
@echo on
