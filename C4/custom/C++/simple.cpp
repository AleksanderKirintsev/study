#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    srand ( time ( NULL ) );

    ifstream input ( "tests\\00" );
    ofstream output ( "tests\\out_simple" );

    const int N = 10; // 4 байта
    int max, q = 0, a[N]; // 8 байт

    for ( int i = 0; i < N; i++ )
        input >> a[i];

    max = a[0];
    for ( int i = 0; i < N; i++ )
        if ( a[i] > max )
            max = a[i];

    for ( int i = 0; i < N; i++ )
        if ( a[i] == max )
            q++;

    output << q;

    return 0;
}
