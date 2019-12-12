@echo off

g++ -std=c++11 -O2 -Wl,--stack,67108864 %~n0.cpp -o %~n0.exe
set dst=tests

FOR %%i IN (%dst%\1*.a) DO (
%~n0.exe < %dst%\%%~ni > %dst%\%%~ni.out
fc /a %dst%\%%~ni.a %dst%\%%~ni.out 
)
del %~n0.exe %dst%\*.out
pause 
