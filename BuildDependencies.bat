@echo off

set WORKDIR=.\bin
set ENGINEBIN=.\Dependencies\FORGE\FORGE\bin

git submodule update --init --recursive

echo Fin de la actualizacion de submodulos, continua si termino correctamente
pause

cd Dependencies\FORGE\FORGE
call BuildFORGE.bat
cd ..\..\..

xcopy /y "%ENGINEBIN%\*.dll" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\plugins.cfg" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE.exe" "%WORKDIR%"
xcopy /y "%ENGINEBIN%\FORGE_d.exe" "%WORKDIR%"

del %WORKDIR%\UxiaANecoraDeMontealto.exe
del %WORKDIR%\UxiaANecoraDeMontealto_d.exe
xcopy /y %WORKDIR%\FORGE.exe %WORKDIR%\UxiaANecoraDeMontealto.exe
xcopy /y %WORKDIR%\FORGE_d.exe %WORKDIR%\UxiaANecoraDeMontealto_d.exe

pause