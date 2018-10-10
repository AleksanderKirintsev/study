#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    double a, q = 1e6 + 1, z = 0;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> a;

        if ( a > 1.0000000 ) {
            ans++;
            q = min ( a, q );
        } else
            z = max ( a, z );

    }
    cout << (ans == 0 ? 1 : ans) << " " << fixed << setprecision(1) << (q == 1e6+1 ? z : q) ;
    return 0;
}
