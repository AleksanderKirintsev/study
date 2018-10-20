#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


#define NLIM 10
#define TLIM 10
int main() {
    int n, h[10], m[10], s[10], ans;

    srand ( time ( NULL ) );

    for ( int t = 3; t < TLIM; t++ ) {
        n = 1 + rand() % NLIM;
        cout << n << endl;

        for ( int i = 0; i < n; i++ ) {
            h[i] = rand() % 24;
            m[i] = rand() % 60;
            s[i] = rand() % 60;
            cout << h[i]/10 << h[i]%10 << ":" << m[i]/10 << m[i]%10 << ":" << s[i]/10 << s[i]%10 << endl;
        }

        cin >> ans;
        cout << endl;
        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) );
        infile << n << endl;

        for ( int i = 0; i < n; i++ ) {
            infile << h[i]/10 << h[i]%10 << ":" << m[i]/10 << m[i]%10 << ":" << s[i]/10 << s[i]%10 << endl;

        }
        infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) + ".a" );
        afile << ans;
        afile.close();
    }


    return 0;
}
