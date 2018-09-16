@echo off
g++ -std=c++11 %~n0.cpp -o %~n0.exe
rem %dst%
FOR %%i IN ("tests\*.a") DO (
%~n0.exe < tests\%%~ni > tests\%%~ni.out
fc /a tests\%%~ni.a tests\%%~ni.out 
)
del %~n0.exe
pause 

