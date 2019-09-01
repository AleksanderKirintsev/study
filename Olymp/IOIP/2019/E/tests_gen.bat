@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
set dst=tests

FOR /L %%i IN (0,1,9) DO %~n0.exe 7 %%i > tests\1%%i
del %~n0.exe
pause 

