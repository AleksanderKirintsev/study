#include <iostream>

using namespace std;

int main() {
    cin.tie ( 0 );
    cin.sync_with_stdio ( 0 );
    cout.tie ( 0 );

    short int n, m;
    cin >> n >> m;

    short int x, winner, q[n + 1] = {}, max = 0;

    for ( int i = 0; i < m; i++ ) {
        cin >> x;
        q[x]++;

        if ( max < q[x] ) {
            max = q[x];
            winner = x;
        }
    }
    cout << winner;
    return 0;
}
