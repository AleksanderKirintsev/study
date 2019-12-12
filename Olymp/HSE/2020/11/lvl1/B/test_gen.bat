@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe

rem %~n0.exe 10 70 1 > tests\11
rem %~n0.exe 10 70 2 > tests\12
rem %~n0.exe 10 70 3 > tests\13
rem %~n0.exe 10 70 4 > tests\14

for /l %%i in (0,1,9) do %~n0.exe 20 5 %%i > tests\1%%i
for /l %%i in (0,1,9) do %~n0.exe 100 20 %%i > tests\2%%i
for /l %%i in (0,1,9) do %~n0.exe 200 40 %%i > tests\3%%i
for /l %%i in (0,1,9) do %~n0.exe 2000 100 %%i > tests\4%%i

rem %~n0.exe 10 100 5 > tests\14
rem %~n0.exe 100 100 6 > tests\20
rem %~n0.exe 200 100 7 > tests\21
del %~n0.exe
pause


