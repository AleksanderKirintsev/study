@echo off
g++ -std=c++11 %~n0.cpp -o %~n0.exe
%~n0.exe > tests\01
rem del %~n0.exe 
