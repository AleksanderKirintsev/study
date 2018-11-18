#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int main() {
    srand ( time ( NULL ) );
    for ( int t = 2; t < 10; t++ ) {
        int n = 1 + rand() % 5,a,b,c,d;
        string s = "";

        for(int i = 0; i < n; i++)
            s.push_back(97 + rand() % 3);
        cout << n << " " << s << endl;
        cin >> a >> b >> c >> d;

        char buffer[20];
        sprintf(buffer, "tests/%02d", t);
        ofstream infile(buffer);
        ofstream afile(string(buffer) + ".a");
        infile << n << endl << s << endl;
        sprintf(buffer, "Yes\n%d %d %d", b, c, d);
        afile << (a ? buffer : "No");
        infile.close();
        afile.close();
    }
    return 0;
}
