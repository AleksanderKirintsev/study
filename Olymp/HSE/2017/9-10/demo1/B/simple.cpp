#include <iostream>
using namespace std;
int n, k, a[27];


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
int main() {
    cin >> n >> k;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];
    cout << simple();
    return 0;
}
