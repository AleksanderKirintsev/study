@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe

for /l %%i in (0,1,9) do %~n0.exe 1000 800 1 %%i > tests\1%%i
for /l %%i in (0,1,9) do %~n0.exe 50 1000 25 %%i > tests\2%%i
for /l %%i in (0,1,9) do %~n0.exe 200 5000 45 %%i > tests\3%%i
for /l %%i in (0,1,9) do %~n0.exe 1000 500000 800 %%i > tests\4%%i

del %~n0.exe
pause


