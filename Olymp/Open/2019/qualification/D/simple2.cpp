#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    long long int n, q, l, r;
    cin >> n >> q;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int d = 0; d < q; d++) {
        char c;
        cin >> c >> l >> r;
        l--;
        if (c == '!')
            a[l] = r;
        else {
            int b[r - l + 1];
            b[r - l] = n + 2;
            for (int i = l; i < r; i++)
                b[i - l] = a[i];

            sort (b, b + (r - l + 1));

            if (b[0] != 0)
                cout << 0 << '\n';
            else {
                int i;
                for (i = 0; b[i + 1] - b[i] <= 1;)
                    i++;

                cout << b[i] + 1 << '\n';
            }
        }
    }
    return 0;
}
