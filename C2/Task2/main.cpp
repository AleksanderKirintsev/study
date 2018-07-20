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
        a[i] = 1 + rand() % 100; // случайные числа от 1 до 100

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
        if ( a[i] > 20 )
        {
            s += a[i];
            x++;
        }

    if ( x > 0 )
        cout << s / x;
    else
        cout << 0;

    return 0;
}
