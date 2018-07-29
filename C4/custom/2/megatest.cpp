#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int main()
{
    srand ( time ( NULL ) );

    int n;
    n = rand() % 6 + 5;
    cout << n << endl;

    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = 1 + rand() % 20;
        cout << a[i] << " ";
    }

    return 0;
}
