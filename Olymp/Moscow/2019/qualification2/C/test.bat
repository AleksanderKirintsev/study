@echo off
g++ -std=c++11 %~n0.cpp -o %~n0.exe
%~n0.exe

del %~n0.exe
pause 
