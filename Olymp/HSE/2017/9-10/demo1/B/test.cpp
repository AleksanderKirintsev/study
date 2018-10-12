#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int n, a[200000], k;

int simple () {
    int smin = 2e9;
    if ( n - k <= 1 )
        return 0;
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
    int m = 1e9 + 273;
    if ( n - k <= 1) {
        return 0;
    }
    sort ( a, a + n );

    for ( int i = 0; i + ( n - k ) <= n; i++ )
        if ( abs ( a[i] - a[i + ( n - k - 1 )] ) < m )
            m = abs ( a[i] - a[i + ( n - k - 1 )] );
    return m;
}
#define NLIM 15
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
