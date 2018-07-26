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
    ofstream output ( "tests\\out_optimal" );

    const int N = 10; // 4 байта
    int max = 0, q = 1, a; // 12 байт

    for ( int i = 0; i < N; i++ )
    {
        input >> a;

        if ( a == max )
            q++;

        if ( a > max )
        {
            max = a;
            q = 1;
        }


    }

    output << q;

    input.close();
    output.close();

    return 0;
}
