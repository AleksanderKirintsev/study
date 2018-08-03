#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    srand ( time ( NULL ) );
    const int N = 10;
    int a[N], i, j = 0, x;

    for ( i = 0; i < N; ++i )
        a[i] = rand() % 20; // случайные числа от 0 до 100
    x = rand() % 20;// случайное число 0 до 100

    for ( i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl << x << endl;


    for ( i = N - 1; i >= 0; --i )
        if ( a[i] == x )
            j = i + 1;

    cout << ( j > 0 ? to_string ( j ) : "No elements" );

    return 0;
}
