#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int n, sum = 0, q = 1;
    cin >> n;
    int a[n + 1];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);

    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1] && a[i] != 1)
            q++;
        if (q == a[i]) {
            if (a[i] > 1)
                i++;
            sum += q;
            q = 1;
        }
        if (a[i] != a[i + 1])
            q = 1;
    }
    cout << sum;
    return 0;
}
