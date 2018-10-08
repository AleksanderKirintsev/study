#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


#define NLIM 10
#define ALIM 100
#define MLIM 10
#define TLIM 15
int main() {
    int n, m, a, b, ans;

    srand ( time ( NULL ) );

    for ( int t = 4; t < TLIM; t++ ) {
        n = 1 + rand() % NLIM;
        m = n + MLIM - rand() % ( MLIM / 2 );
        a = 1 + rand() % ALIM;
        b = 1 + rand() % ALIM;


        //cout << n << endl << m  << endl << a << endl << b << endl;

        if ( n >= m )
            cout << 0;
        int x = m - n, y = 0, s = a * x;
        do {
            x = max ( x - 4, 0 );
            y++;
            s = min ( a * x + b * y, s );
        } while ( x > 0 );
        //cout << s;




        cout << endl;
        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
        infile << n << endl;
        infile << m << endl;
        infile << a << endl;
        infile << b << endl;
        infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << s;
        afile.close();
    }


    return 0;
}
