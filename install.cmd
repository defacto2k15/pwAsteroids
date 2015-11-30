@ECHO OFF
:: Location for the project:
SET projectplace=VSProject
::
ECHO *********************************************************************
ECHO ** This script will prepare a project for Visual Studio with CMake **
ECHO **      which will let you to build pwAsteroids on Windows.        **
ECHO *********************************************************************
ECHO Parameters to the script:
ECHO - path to the boost folder (the place where you have built boost):
SET boostpath=%~1
ECHO    %boostpath%
ECHO - path to the Allegro folder (containing bin, include and lib folders):
SET allegropath=%~2
ECHO    %allegropath%
::
IF "%allegropath%"=="" goto end
::
IF NOT EXIST %projectplace% MKDIR %projectplace%
ECHO Project location: %projectplace%

CD %projectplace%
ECHO Running CMake:
cmake -Dboostpath:string="%boostpath%" -Dallegropath:string="%allegropath%" .. -G "Visual Studio 14"
CD ..
ECHO *********************************************************************
ECHO.> %projectplace%\pwAsteroids.vcxproj.user
(
ECHO ^<?xml version="1.0" encoding="utf-8"?^>
ECHO ^<Project ToolsVersion="14.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003"^>
ECHO   ^<PropertyGroup Condition="'$(Configuration)|$(Platform)'=='Debug|Win32'"^>
ECHO     ^<LocalDebuggerEnvironment^>PATH=%allegropath%\^bin;%%PATH%%^</LocalDebuggerEnvironment^>
ECHO     ^<DebuggerFlavor^>WindowsLocalDebugger^</DebuggerFlavor^>
ECHO   ^</PropertyGroup^>
ECHO ^</Project^>
)> "%projectplace%\pwAsteroids.vcxproj.user"
ECHO Added environment variable to %projectplace%\pwAsteroids.vcxproj.user
:end
:: install.cmd "C:\Program Files\boost\boost_1_59_0" "C:\allegro\allegro-5.0.10-msvc-11.0"