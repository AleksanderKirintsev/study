#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    long long int n, q, l, r;
    cin >> n >> q;
    int a[n],ans[q]= {-1};

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int o = 0; o < q; o++) {
        char c;
        cin >> c >> l >> r;
        l--;
        r--;

        if (c == '!')
            a[l] = r + 1;
        else {
            int b[r - l + 2];
            b[r - l + 1] =n + 2;
            for (int i = l; i <= r; i++)
                b[i - l] = a[i];

            sort (b, b + (r - l + 1));

            if (b[0] != 0)
                cout << 0 << '\n';
            else {
                for (int i = 0; i <= r - l; i++)
                    if (b[i + 1] - b[i] > 1) {
                        cout << b[i] + 1 << '\n';
                        break;
                    }
            }
        }

    }
    return 0;
}
