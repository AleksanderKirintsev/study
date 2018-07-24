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
    int k = 0, j = -1;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
    {

        if ( a[i] > 0 )
            k++;

        if ( k == 3 )
        {
            j = i + 1;
            break;
        }
    }

    cout << j;

    return 0;

}
