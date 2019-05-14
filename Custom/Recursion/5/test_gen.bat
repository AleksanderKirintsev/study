@echo off

g++ -std=c++11 %~n0.cpp -o %~n0.exe

%~n0.exe 10 70 1 > tests\10
%~n0.exe 10 70 2 > tests\11
%~n0.exe 10 70 3 > tests\12
%~n0.exe 10 70 4 > tests\13
%~n0.exe 10 100 5 > tests\14
%~n0.exe 100 100 6 > tests\15
%~n0.exe 200 100 7 > tests\16
del %~n0.exe


