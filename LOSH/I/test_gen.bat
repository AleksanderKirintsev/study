rem @echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
for /l %%i in (1,1,4) do %~n0.exe 5 %%i > tests\1%%i

del %~n0.exe



