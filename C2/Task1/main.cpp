#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );
    const int N = 20;
    int a[N];
    int min = 1000;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 1000; // случайные числа от 0 до 1000

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N ; ++i )
        if ( a[i] % 2 == 0 && a[i] % 3 != 0 && a[i] < min )
            min = a[i];

    cout << min;
    return 0;
}
