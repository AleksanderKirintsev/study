#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


#define NLIM 10
#define ALIM 20
#define MLIM 10
#define TLIM 3
int main() {
    int n, p, q, ans[2];

    srand ( time ( NULL ) );

    for ( int t = 2; t < TLIM; t++ ) {
        n = 1 + rand() % 15;
        p = 1 + rand()% n;
        q = 1 + rand()% n;
        cout << n << " " << p << " " << q << endl;
        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
        infile << n << " " << p << " " << q << endl;
        infile.close();
        cin >> ans[0] >> ans[1];
        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << ans[0] << " " << ans[1];
        afile.close();
    }


    return 0;
}
