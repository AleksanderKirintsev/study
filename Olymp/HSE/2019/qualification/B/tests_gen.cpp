#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


#define NLIM 20
#define ALIM 20
#define MLIM 10
#define TLIM 15
int main() {
    int n,a[NLIM], ans;

    srand ( time ( NULL ) );

    for ( int t = 2; t < TLIM; t++ ) {
        n = 1 + rand() % NLIM;
        cout << n << endl;
        for (int i = 0; i < n; i++)
            a[i] = 1 + rand() % 5;



        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
        infile << n <<  endl;
        for (int i = 0; i < n; i++)
            infile << a[i] << " ";
        infile.close();

        sort(a,a+n);
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;

        cin >> ans;
        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << ans;
        afile.close();

        cout << endl;
    }

    return 0;
}
