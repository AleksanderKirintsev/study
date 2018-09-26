#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int TMAX = 1e9;
const int TMIN = -273;

int qbite ( int n ) {
    int res = 0;
    while ( n ) {
        res += ( n & 1 ); // прибавить 1, если первый бит равен 1
        n >>= 1; // сдвинуть на 1 бит вправо
    }

    return res;
}

int main() {
    cin.tie ( 0 );
    cin.sync_with_stdio ( 0 );
    cout.tie ( 0 );

    int n = 5, k, a[200000], mins = TMAX - TMIN;
    cin >> n >> k;

    if ( n == k || n - k == 1 ) {
        cout << 0;
    } else {
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        for ( int code = 0; code < ( 1 << n ); code++ ) {
            if ( qbite ( code ) == k ) {
                int tmin = TMAX, tmax = TMIN;

                for ( int i = 0; i < n; i++ )
                    if ( ( ( code & ( 1 << i ) ) == 0 ) ) {

                        if ( a[i] > tmax )
                            tmax = a[i];

                        if ( a[i] < tmin )
                            tmin = a[i];
                    }
                if ( tmax - tmin < mins )
                    mins = tmax - tmin;

            }
        }
        cout << mins;
    }
    return 0;
}
