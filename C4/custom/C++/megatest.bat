@echo off
g++ simple.cpp -o simple.exe
g++ optimal.cpp -o optimal.exe
g++ megatest.cpp -o megatest.exe

for /L %%I in (1,1,10000) do (
megatest.exe > megatest.out
simple.exe < megatest.out > simple.out
optimal.exe < megatest.out > optimal.out
fc /a simple.out optimal.out
)

del *.exe 
pause