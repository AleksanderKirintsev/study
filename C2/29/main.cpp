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
    int max1, max2;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 1000; // случайные числа от 1 до 1000

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    max1 = a[0];
    max2 = a[1];

    if ( max2 > max1 )
    {
        int tmp = max2;
        max2 = max1;
        max1 = tmp;
    }

    for ( int i = 0; i < 30; ++i )
        if ( a[i] > max1 )
            max1 = a[i];

    for ( int i = 0; i < 30; ++i )
        if ( a[i] > max2 && a[i] < max1 )
            max2 = a[i];

    cout << max2;

    return 0;

}
