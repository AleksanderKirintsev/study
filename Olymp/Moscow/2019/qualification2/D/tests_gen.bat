rem @echo off
g++ -std=c++11 %~n0.cpp -o %~n0.exe

for /L %%i in (0,1,9) do %~n0.exe 20 5 %%i > tests\1%%i
for /L %%i in (0,1,9) do %~n0.exe 30 7 %%i > tests\2%%i
for /L %%i in (0,1,9) do %~n0.exe 40 11 %%i > tests\3%%i
for /L %%i in (0,1,2) do %~n0.exe 1000010 100001 %%i > tests\4%%i

del %~n0.exe 
pause