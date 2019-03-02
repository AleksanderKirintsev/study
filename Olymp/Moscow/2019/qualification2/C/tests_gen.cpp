#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


#define NLIM 10
#define ALIM 200
#define MLIM 10
#define TLIM 10
int main() {
    int n, m, a[10],  ans;

    srand ( time ( NULL ) );

    for ( int t = 2; t < TLIM; t++ ) {

        m = 1 + rand() % MLIM;
        n = m + rand() % ( NLIM - m + 1 );
        for ( int i = 0; i < n; i++ )
            a[i] = -100 + rand() % ( ALIM + 1 );


        cout << n << " " << m << endl;
        for ( int i = 0; i < n; i++ )
            cout << a[i] << " ";
        cout << endl;

        cin >> ans;

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) );
        infile << n << " " << m << endl;
        for ( int i = 0; i < n; i++ )
            infile << a[i] << " ";

        infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) + ".a" );
        afile << ans;
        afile.close();
    }


    return 0;
}
