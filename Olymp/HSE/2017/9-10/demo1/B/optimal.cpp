#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200000], k;

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
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> k;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];

    cout << optimal();
    return 0;
}
