#include <iostream>
#include <iomanip>
using namespace std;

struct TR {
    int q;
    double p, m;
};

int n;
double a[27];

TR simple () {
    TR r = {0, 0, 1e6};

    for (int c = 1; c < (1 << n); c++) {
        int q = __builtin_popcount (c);
        double p = 1, m = 1e6;

        for (int i = 0; i < n; i++) {
            if ( (c & (1 << i)) > 0) {
                p *= a[n-i-1];
                m = min (a[n-i-1], m);
            }
        }

        if (p > r.p || (p == r.p && q < r.q))
            r = {q, p, m};

    }
    return r;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    TR ans = simple();
    printf ("%d %0.1f", ans.q, ans.m);
    return 0;
}
