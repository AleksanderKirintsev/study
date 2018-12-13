#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define NLIM 10
#define DLIM 15
struct Meet{
    int a,b,t;
    };
int main() {
    srand(time(0));
    int n,d,ans[3];

    for ( int t = 3; t < 9; t++ ) {
        n = NLIM - rand() % ( NLIM / 2 );
        d = DLIM - rand() % ( DLIM / 2 );

        Meet p[n];
        for ( int i = 0; i < n; i++ ) {
            p[i].a = 1 + rand() % NLIM;
            p[i].b = 1 + rand() % NLIM;
            if (p[i].a == p[i].b && i % 2 == 0) p[i].b - (1 + rand() % (n - 1));
            else if (p[i].a == p[i].b && i % 2 == 1) p[i].a - (1 + rand() % (n - 1));
            p[i].t = (1 + rand() % 30) * (1 + rand() % 4);
        }

        if (rand() % 2 == 0)
            p[rand() % n].a = 1;
        else
            p[rand() % n].b = 1;

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ));
        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );

        infile << n << " " << d << endl;
        for ( int i = 0; i < n; i++ )
            infile << p[i].a << " " << p[i].b << " " <<p[i].t << endl;

        sort (p, p + n, [](const Meet &l, const Meet &r) {return l.t < r.t;});

        cout << n << " " << d << endl;
        for ( int i = 0 ; i < n; i++)
            cout << p[i].a << " " << p[i].b << " " <<p[i].t << endl;
        cout << endl;
        cin >> ans[0] >> ans[1] >> ans[2];

        afile << ans[0] << " " << ans[1] << " " << ans[2];

        infile.close();
        afile.close();
    }
    return 0;
}
