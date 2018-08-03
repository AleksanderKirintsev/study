#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );

    const int N = 30;
    int a[N], j = 0;
    double s = 0;

    for ( int i = 0; i < N; ++i )
        a[i] = rand() % 2000 - 1000; // случайные числа от -1000 до 1000

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
        if ( abs ( a[i] % 10 ) == 5 )
        {
            s += a[i];
            j++;
        }

    cout << s / j;

    return 0;
}
