#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if ( n == k || n - k == 1 ) {
        cout << 0;
        return 0;
    }

    vector<int> t ( n );

    for ( int i = 0; i < n; i++ )
        cin >> t[i];

    sort ( t.begin(), t.end() );


    int i = 0, j = t.size()-1;

    for ( ; k > 0; ) {
        if ( abs(t[i]) > abs(t[j]) ) {
            i++;
            k--;

        } else {
            j--;
            k--;

        }

    }

cout << abs(t[j]-t[i]);
return 0;
}
