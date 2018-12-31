#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
using namespace std;
#define NLIM 10
int main() {
    srand ( time ( NULL ) );
    for ( int t = 2; t < 10; t++ ) {
        int n = NLIM - rand() % (NLIM/2);
        int m = (n*(n-1)/2) - rand() % (n*(n-1)/2);
        int a[n],b[m*2];

        for(int i = 0; i < n; i++){
            a[i] = i+1;
            b[i] = i+1;
            }

        random_shuffle(a, a + n);
        random_shuffle(b, b + m * 2);

        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < m; i+=2)
            cout << b[i] << " " << b[i+1] << endl;

        int ans;
        cin >> ans;

        char buffer[20];
        sprintf(buffer, "tests/%02d", t);
        ofstream infile(buffer);
        ofstream afile(string(buffer) + ".a");

        infile << n << " " << m << endl;
        afile << ans;

        infile.close();
        afile.close();
    }
    return 0;
}
