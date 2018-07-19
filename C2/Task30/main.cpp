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
    int k = 0;
    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N; ++i )
    {
        cin » a[i];
        if ( a[i] > 0 )
            k++;
        if ( k == 3 )
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;

    return 0;

}
