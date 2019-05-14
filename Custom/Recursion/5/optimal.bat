@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
set dst=tests

FOR %%i IN (%dst%\1?) DO (
%~n0.exe < %dst%\%%~ni > %dst%\%%~ni.a
rem fc /a %dst%\%%~ni.a %dst%\%%~ni.out 
)
del %~n0.exe %dst%\*.out
pause 
