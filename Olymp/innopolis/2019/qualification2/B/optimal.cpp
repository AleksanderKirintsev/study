#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

ll disc(ll h) {
    double D = 1 + 8 * h;
    return ((-1 + floor(sqrt(D)))/2);
}

ll count(ll m, ll k) {
    ll h = m / k;
    ll n = disc(h);
    ll r = m - (n + 1) * n / 2 * k;
    return (n * k + r / (n+1));
}
int main() {
    //freopen("tests/00","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    ll t,m,k;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> k;
        cout << count(m,k) << '\n';
    }
    return 0;
}
