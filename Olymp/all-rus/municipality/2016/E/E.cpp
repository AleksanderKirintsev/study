#include <iostream>
using namespace std;

int main() {
    int n, ans = 100000;
    cin >> n;

    int a[n + 1];
    for (int i = n; i > 0; i--)
        cin >> a[i];
    a[0] = 0;
    n++;

    for (int c = (1 << n - 2); c < (1 << n); c++) {
        int sum = 0;
        bool f = true;

        for (int i = 0; i < n - 1; i++) {
            if ( (c & (1 << i)) == 0 && (c & (1 << i + 1)) == 0) {
                f = false;
                break;
            }
            if ( (c & (1 << i)) > 0)
                sum += a[i];
            if (i == n - 2 && (c & (1 << i + 1)) > 0)
                sum += a[i + 1];

        }
        ans = (f == true ? min (ans, sum) : ans);
    }
    cout << ans;
    return 0;
}
