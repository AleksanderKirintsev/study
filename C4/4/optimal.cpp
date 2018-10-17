#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    double a, q = 1e6 + 1, z = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > 1.0000000) {
            ans++;
            q = min (a, q);
        } else
            z = max (a, z);
    }

    ans = (ans == 0 ? 1 : ans);
    q = (q == 1e6 + 1 ? z : q);

    printf ("%d %0.1f", ans, q);

    return 0;
}
