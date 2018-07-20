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
        a[i] = rand() % 100; // случайные числа от 0 до 100

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
        s += a[i];

    s = s / N;

    for ( int i = 0; i < N; ++i )
        if ( a[i] > s )
            j++;

    cout << j;

    return 0;
}
