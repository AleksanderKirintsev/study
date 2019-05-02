@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe

%~n0.exe 10 70 > tests\10
%~n0.exe 10 100 > tests\11
%~n0.exe 100 100 > tests\12
%~n0.exe 200 100 > tests\13
del %~n0.exe

