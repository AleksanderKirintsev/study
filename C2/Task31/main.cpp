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
    int k = 0, max;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;


    max = a[0] + a[1];

    for ( int i = 0; i < N-1; ++i )
        if ( a[i] + a[i + 1] > max )
        {
            max = a[i] + a[i + 1];
            k = i + 1;
        }

    cout << k;
    return 0;

}
