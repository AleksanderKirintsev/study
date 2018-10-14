#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200000], k;

int optimal() {
    int m = 1e9 + 273;

    if ( n - k <= 1 ) {
        return 0;
    }
    sort ( a, a + n );

    for ( int i = 0; i + ( n - k ) <= n; i++ )
        if ( abs ( a[i] - a[i + ( n - k - 1 )] ) < m )
            m = abs ( a[i] - a[i + ( n - k - 1 )] );

    return m;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> k;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];

    cout << optimal();
    return 0;
}
