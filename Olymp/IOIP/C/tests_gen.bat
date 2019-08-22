@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
set dst=tests

FOR /L %%i IN (0,1,9) DO %~n0.exe 2  %%i > tests\1%%i
FOR /L %%i IN (0,1,9) DO %~n0.exe 3  %%i > tests\2%%i
FOR /L %%i IN (0,1,9) DO %~n0.exe 5  %%i > tests\3%%i
FOR /L %%i IN (0,1,9) DO %~n0.exe 10 %%i > tests\4%%i
pause 

