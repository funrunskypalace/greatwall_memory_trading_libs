
set curdir=%cd%
cd ..
set rootdir=%cd%
mkdir dist
cd dist
mkdir win64
cd win64
mkdir lib
copy /Y %rootdir%\app_home\bin\skypalace_framework.dll %rootdir%\dist\win64\lib\skypalace_framework.dll
copy /Y %rootdir%\app_home\bin\skypalace_frameworkd.dll %rootdir%\dist\win64\lib\skypalace_frameworkd.dll
copy /Y %rootdir%\app_home\lib\skypalace_framework.lib %rootdir%\dist\win64\lib\skypalace_framework.lib
copy /Y %rootdir%\app_home\lib\skypalace_frameworkd.lib %rootdir%\dist\win64\lib\skypalace_frameworkd.lib
xcopy  "%rootdir%\include\*" "D:\dev-kecheng\StratRunner_windows\dist\win64\include\" /s/h/e/k/f/c/Y
cd %curdir%