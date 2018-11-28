#include <iostream>
#include <map>
using namespace std;

#define F first
#define S second

int main() {
    int n, key, q = 0;
    map <int, int>g;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        g[key]++;
    }

    for (auto& k : g)
        q += k.F * (k.S / k.F);

    cout << q;
    return 0;
}
