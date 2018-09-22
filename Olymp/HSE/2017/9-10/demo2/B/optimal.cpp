#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    int a, b, c, d, n;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> a >> b >> c >> d;
        cout << ((b == 1 && b * c + a == d) || (b > 1 && b * c + a <= d) ? "YES" : "NO") << '\n';

    }

    return 0;
}
