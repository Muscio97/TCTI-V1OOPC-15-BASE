@echo off
title Workspace updater
color f

:test
ping localhost -n 1 > NUL
tasklist /FI "IMAGENAME eq codelite.exe" 2>NUL | find /I /N "codelite.exe">NUL
cls
if "%ERRORLEVEL%"=="0" echo Please close Codelite first.
if "%ERRORLEVEL%"=="0" goto test
c:/python34/python bmptk-mef.py
cls
start "" "C:\Program Files\CodeLite\codelite.exe"
exit /b