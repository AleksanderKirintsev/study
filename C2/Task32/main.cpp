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
    int min1, min2;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10

    min1 = a[0];
    min2 = a[1];
    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";

    cout << endl;
    for ( int i = 0; i < N; ++i )
        for ( int j = 0; j < N; ++j )
            if ( abs ( a[i] + a[j] ) < abs ( min1 + min2 ) && i != j )
            {
                min1 = a[i];
                min2 = a[j];
            }
    cout << min1 << " " << min2;

    return 0;
}
