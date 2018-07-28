@echo off
g++ optimal.cpp -o optimal.exe

optimal.exe < tests\00 > tests\00.out
 fc /a tests\00.a tests\00.out

optimal.exe < tests\01 > tests\01.out
 fc /a tests\01.a tests\01.out

optimal.exe < tests\02 > tests\02.out
 fc /a tests\02.a tests\02.out

optimal.exe < tests\03 > tests\03.out
 fc /a tests\03.a tests\03.out

optimal.exe < tests\04 > tests\04.out
 fc /a tests\04.a tests\04.out

del tests\*.out optimal.exe
pause