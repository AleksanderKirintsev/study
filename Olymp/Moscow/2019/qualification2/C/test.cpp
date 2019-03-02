#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

#define NLIM 7
int n, a[NLIM], k;

int simple () {
    if ( n - k <= 1 )
        return 0;

    int smin = 2e9;
    for ( int c = 0; c < ( 1 << n ); c++ ) {
        if ( __builtin_popcount ( c ) == k ) {
            int tmin = 1e9, tmax = -273;
            for ( int i = 0; i < n; i++ )
                if ( ( ( c & ( 1 << i ) ) == 0 ) ) {
                    tmin = min ( tmin, a[i] );
                    tmax = max ( tmax, a[i] );
                }
            smin = min ( smin, tmax - tmin );
        }
    }
    return smin;
}

int optimal() {
    if ( n - k <= 1)
        return 0;

    sort ( a, a + n );

    int m = 1e9 + 273;
    for ( int i = 0; i <= k; i++ )
        m = min (m, a[i+ n - k - 1] - a[i]);

    return m;
}

int main() {
    srand ( time ( NULL ) );
    for ( int t = 0; t < 100000; t++ ) {
        k = rand() % ( NLIM + 1 );
        n = k + rand() % ( NLIM - k + 1 );
        for ( int i = 0; i < n; i++ )
            a[i] = rand() % 201 - 100;

        if ( simple() != optimal() ) {
            cout << "error!" << endl;
            return 0;
        }
    }
    cout << "done!" << endl;
    return 0;
}
