#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, n, ans[10];
    cin >> n;
    for ( int i = 0; i < n; i++ ) {

        cin >> a >> b >> c >> d;
        if (b == 1 && b * c + a == d) ans[i] = 1;
        else if (b == 1 && b * c + a != d ) ans[i] = 0;
        else {
        if ( b * c + a <= d )
            ans[i] = 1;
        else
            ans[i] = 0;
            }
    }
    for ( int i = 0; i < n; i++ ) {
        if ( ans[i] == 1 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
