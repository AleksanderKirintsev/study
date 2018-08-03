#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );
    const int N = 30;
    int a[N], x = 0;
    double s = 0;

    for ( int i = 0; i < N; ++i )
        a[i] = rand() % 41 - 20; // случайные числа от -20 до 20

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
        if ( a[i] > 0 )
        {
            s += a[i];
            x++;
        }

    cout << ( x > 0 ? s / x : 0 );

    return 0;
}
