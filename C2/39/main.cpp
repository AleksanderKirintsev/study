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
    int l = 0, lmax = 0, k = 0, kmax = 0;

    for ( int i = 0; i < N; ++i )
        a[i] = rand() % 100; // случайные числа от 0 до 100

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
    {
        for ( int j = 1; j <= a[i]; j++ )
            if ( a[i] % j == 0 )
                l++;

        if ( l > lmax )
        {
            lmax = l;
            k = i + 1;
            l = 0;
        }
    }
    cout << k;
    return 0;
}
