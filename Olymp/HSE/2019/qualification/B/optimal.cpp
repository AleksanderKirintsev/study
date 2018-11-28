#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n, ans = 0, q = 1;
    cin >> n;
    int a[n + 1];
    a[n] = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);

    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1])
            q++;
        else {
            ans += a[i] * (q / a[i]);
            q = 1;
        }
    }

    cout << ans;
    return 0;
}
