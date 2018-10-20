#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define ll long long

long long int n, m;
int a, b;

int simple() {
    if (n >= m)
        return 0;
    int x = m - n, y = 0, s = a * x;
    do {
        x = max (x - 4, 0);
        y++;
        s = min (a * x + b * y, s);
    } while (x > 0);
    return s;
}

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
    srand (time (0));
    int q = 0;
    for (int i = 0; i < 100000; i++) {
        n = 1 + rand() % 20;
        m = 1 + rand() % 20;
        a = 1 + rand () % 100;
        b = 1 + rand () % 100;
        if (optimal() != simple()) {
            cout << "error! " << i << endl;
            return 0;
        }
    }

    cout << "done!" << endl;
    return 0;
}
