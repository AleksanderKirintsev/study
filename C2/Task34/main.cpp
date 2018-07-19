#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );
    const int N = 30;
    int a[N];
    int min, max;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10
    min = a[0];
    max = a[0];
    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";

    cout << endl;
    for ( int i = 0; i < N; ++i )
    {
        if ( a[i] > max )
            max = a[i];
        if ( a[i] < min )
            min = a[i];
    }
    cout << max - min;
    return 0;
}
