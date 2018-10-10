#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int n, q = 0, mq = 1,ans = 1;
double a[int ( 2e5 )];

double simple () {
    double smin = 1e6 + 1, z = 0;

    for ( int c = 0; c < ( 1 << n ); c++ ) {
        if ( __builtin_popcount ( c ) < n ) {
            q = 0;
            for ( int i = 0; i < n; i++ )
                if ( ( ( c & ( 1 << i ) ) == 0 ) ) {
                    if ( a[i] > 1 ) {
                        smin = min ( smin, double ( a[i] ) );
                        q++;
                    } else
                        z = max ( z, double ( a[i] ) );
                }
            mq = max ( mq, q );
        }
    }
    return ( smin == 1e6 + 1 ? z : smin );
}


double optimal() {
    double smin = 1e6 + 1, z = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] > 1.0000000 ) {
            ans++;
            smin = min ( a[i], smin );
        } else
            z = max ( a[i], z );

    }
    if (smin == 1e6 + 1) ans  = 1;
    return ( smin == 1e6 + 1 ? z : smin ) ;
}

int main() {
    srand(time(0));
    int c, b,d = 0;
    for (int t = 0; t < 10000; t++){

    n = 3 + rand()% 8;

    for (int i = 0; i < n; i++){
        string s;
        c = rand() % 11;
        b = rand() % 10;
        s += to_string(c);
        s += ".";
        s += to_string(b);
        a[i] = atof(s.c_str());
        }
    if (simple() != optimal())
        d++;

    }
    cout << d << " done!";
    return 0;
}
