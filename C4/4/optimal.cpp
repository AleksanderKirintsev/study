#include <iostream>
using namespace std;

#define Q first
#define M second

int n;
double a[1000];

pair<int, double> optimal() {
    pair<int, double> r = {0, 1e6 + 1};
    double z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1.0000000) {
            r.Q++;
            r.M = min (a[i], r.M);
        } else
            z = max (a[i], z);

    }
    if (r.M == 1e6 + 1) {
        r.Q = 1;
        r.M = z;
    }

    return r;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    pair <int,double> ans = optimal();

    printf ("%d %0.1f", ans.Q, ans.M);

    return 0;
}
