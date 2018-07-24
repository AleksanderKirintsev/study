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
    int k = 1, kMax = 1;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 100

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N - 1; ++i )
        if ( a[i] == a[i + 1] )
        {
            k++;
            if ( k > kMax )
                kMax = k;
        }
        else
        {
            if ( k > kMax )
                kMax = k;
            k = 1;
        }

    cout << kMax;

    return 0;
}
