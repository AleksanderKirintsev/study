#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k, x, m;
    cin >> n >> k >> x;

    m = ceil (x / double (n - k));

    cout << x + ((long long)m) * k;
    return 0;
}
