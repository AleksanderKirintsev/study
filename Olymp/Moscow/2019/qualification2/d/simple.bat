@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe
set dst=tests

%~n0.exe < %dst%\100 > %dst%\101.txt


del %~n0.exe
