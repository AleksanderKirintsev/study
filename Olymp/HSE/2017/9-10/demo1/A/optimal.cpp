#include <iostream>
using namespace std;
#define ll long long

long long int n, m;
int a, b;

int optimal() {
    if (n >= m)
        return 0;

    if (b >= a * 4)
        return (m - n) * a;

    ll q = (m - n) / 4;
    ll r = (m - n) % 4;

    ll x = (a * r < b) ? r : 0;
    ll y = (a * r < b) ? q : q + 1;

    return x * a + y * b;
}

int main() {
    cin >> n >> m >> a >> b;
    cout << optimal();
    return 0;
}
