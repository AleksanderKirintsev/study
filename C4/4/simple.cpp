#include <iostream>
#include <iomanip>
using namespace std;
int n,q = 0,mq = 0;
double a[int(2e5)];

double simple () {
    double smin = 1e6 + 1, z = 0;

    for ( int c = 0; c < ( 1 << n ); c++ ) {
        if ( __builtin_popcount ( c ) < n ) {
            q = 0;
            for ( int i = 0; i < n; i++ )
                if ( ( ( c & ( 1 << i ) ) == 0 ) ) {
                    if ( a[i] > 1 ) {
                        smin = min ( smin, double(a[i]) );
                        q++;
                    } else
                        z = max ( z, double(a[i]));
                }
            mq = max (mq,q);
        }
    }
    return (smin == 1e6+1 ? z : smin);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double ans = simple();
    if (ans <= 1 ) cout << 1 << " " << ans;
    else cout << mq << fixed << setprecision(1) << " " << ans;
    return 0;
}
