#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n, q, l, r;

    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int o = 0; o < q; o++) {
        char c;
        cin >> c >> l >> r;
        l--;
        r--;
        if (c == '!')
            a[l] = r;
        else {
            int b[r - l + 1];
            b[r - l + 1] = n + 2;
            for (int i = l; i < r; i++)
                b[i - l] = a[i];

            sort (b, b + (r - l));

            if (a[0] == 0)
                cout << 0 << endl;
            else {
                for (int i = 0; i < r - l; i++)
                    if (b[i + 1] - b[i] > 1) {
                        cout << b[i] + 1 << endl;
                        break;
                    }
            }
        }

    }
    return 0;
}
