#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

#define NLIM 30

int n,k;

int main() {
    srand(time(0));
    for(int t = 1; t < 9; t++) {
        n = NLIM - rand() % (NLIM - 2);
        k = n/2 - rand() % (n/4);
        k += (k%2 == 0);
        int a[n],ans[n-k+1];

        cout << n << " " << k << endl;
        for(int i = 0; i < n; i++) {
            a[i] = 1+rand()%(NLIM/4);
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n-k+1; i++)
            cin >> ans[i];

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) );
        infile << n << " " << k << endl;
        for(int i = 0; i < n; i++)
            infile << a[i] << " ";

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t ) + ".a" );
        for(int i = 0; i < n-k+1; i++)
            afile << ans[i];
    }
    return 0;
}
