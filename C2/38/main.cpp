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
    for ( int i = 0; i < N; ++i )
        a[i] = rand() % 20 - 10; // случайные числа от -10 до 10

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    if ( a[0] < 0 )
        a[0] = 1;
    else
        a[0] = 0;

    if ( a[1] < 0 )
        a[0]++;
    else
        a[1] = a[0];

    for ( int i = 2; i < N; ++i )
        if ( a[i] < 0 )
        {
            a[0]++;
            if ( a[0] > a[1] )
                a[1] = a[0];
        }
        else
        {
            if ( a[0] > a[1] )
                a[1] = a[0];
            a[0] = 0;
        }

    cout << a[1];
    return 0;
}
