#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );
    int N; // 4 байта
    const int MAXV = 10; // 4 байта
    N = 1 + rand() % 1000; // случайное число от 1 до 1000

    int a[N]; // 40 байт
    int max, q = 0; // 8 байт

    for ( int i = 0; i < N; i++ )
        a[i] = rand() % MAXV; // случайные числа от 0 до 10

    for ( int i = 0; i < N; i++ )
        cout << a[i] << " ";
    cout << endl;

    max = a[0];
    for ( int i = 0; i < N; i++ )
        if ( a[i] > max )
            max = a[i];

    for ( int i = 0; i < N; i++ )
        if ( a[i] == max )
            q++;

    cout << q;

    return 0;
}
