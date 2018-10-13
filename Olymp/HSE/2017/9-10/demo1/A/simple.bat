@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
set dst=tests

FOR %%i IN (%dst%\*.a) DO (
%~n0.exe < %dst%\%%~ni > %dst%\%%~ni.out
fc /a %dst%\%%~ni.a %dst%\%%~ni.out
del %dst%\%%~ni.out
)
del %~n0.exe
pause 
