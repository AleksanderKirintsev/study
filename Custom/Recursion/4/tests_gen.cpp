#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

#define NLIM 10
int main() {
    srand ( time ( NULL ) );
    for(int t = 3; t < 9; t++) {
        int ans,n = NLIM - rand() % (NLIM / 2);
        int x0 = rand() % n,y0 = rand() % n;
        int x1 = rand() % n,y1 = rand() % n;
        cout << n << " " << x0 << " " << y0 << " " << x1 << " " << y1 << endl;

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
        infile << n << " " << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
        infile.close();

        cin >> ans;
        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << ans;
        afile.close();
    }
    return 0;
}
