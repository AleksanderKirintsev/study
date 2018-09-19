#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;


#define NLIM 10
#define TLIM 10
#define ALIM 10
#define BLIM 4
#define CLIM 8
int main() {
    int n, a[NLIM],b[NLIM],c[NLIM],d[NLIM], ans[NLIM];
    string s;
    srand ( time ( NULL ) );

    for ( int t = 1; t < TLIM; t++ ) {
        n = 1 + rand() % NLIM;
        cout << n << endl;

        for (int i = 0; i < n;i++){
        a[i] = 1 + rand() % ALIM;
        b[i] = 1 + rand() % BLIM;
        c[i] = 1 + rand() % BLIM;
        d[i] = a[i] + rand() % (ALIM - a[i] + 1);
        cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
        }
        for (int i = 0; i < n;i++){
        cin >> s;
        if (s == "YES")ans[i] = 1;
        else ans[i] = 0;
        }




        cout << endl;
        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) );
        infile << n << endl;

        for ( int i = 0; i < n; i++ ) {
            infile <<  a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;

        }
        infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) + ".a" );
        for (int i = 0; i < n;i++){
        if (ans[i] == 1) afile << "YES" << endl;
        else afile << "NO" << endl;
        }
        afile.close();
    }


    return 0;
}
