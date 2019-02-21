@echo off
set name=simple
g++ -std=c++11 %name%.cpp -o %name%.exe
set dst=tests

%name%.exe < %dst%\100 > %dst%\100.txt


del %name%.exe
