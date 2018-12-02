#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    for(int i = 0; i < 80; i++)
        cout << rand() % 51 << " ";
    return 0;
}
