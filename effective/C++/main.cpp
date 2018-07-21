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

    int max, q = 1, a; // 12 байт

    max = 0;

    for ( int i = 0; i < N; i++ )
    {
        a = rand() % MAXV;// случайное число от 1 до 10
        cout << a << " ";

        if ( a == max )
            q++;

        if ( a > max )
        {
            max = a;
            q = 1;
        }


    }
    cout << endl << N << endl;

    cout << q;

    return 0;
}
