#include <iostream>
#include <algorithm>
using namespace std;

struct Guests {
    int l, r, num;
};
istream& operator>> (istream& is, Guests& a) {
    cin >> a.l >> a.r;
}
bool operator < (Guests& l, Guests& r) {
    return (l.l < r.l || (l.l == r.l && l.r > r.r));
}

int n;
Guests a[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i].num = i + 1;
    }

    sort (a, a + n);

    for (int i = 0; i < n - 1; i++)   //100.000
        for (int j = i + 1; (j < n || a[j].l > a[i].r) ; j++) {  //100.000 * 100.000
            if (a[j].l <= a[i].r && a[j].r <= a[i].r) {
                a[j].l = -1;
                a[j].r = -1;
            }
            if (a[j].l <= a[i].r && a[j].r > a[i].r)
                a[j].l = a[i].r + 1;
        }

    sort (a, a + n, [] (Guests & l, Guests & r) {return l.num < r.num;});

    for (int i = 0; i < n; i++)  //100.000
        cout << a[i].l << " " << a[i].r << endl;

    return 0;
}
