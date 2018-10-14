#include <iostream>
#include <algorithm>
using namespace std;

struct piramide {
    int w, h;
};
istream& operator>> (istream& is, piramide& a) {
    cin >> a.w >> a.h;
}
bool operator< (piramide& w1, piramide& w2) {
    return (w1.w < w2.w || (w1.w == w2.w && w1.h < w2.h));
}

int n;
piramide a[100000];

int main() {
    long long sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);

    for (int i = 0; i < n;) {
        int m = a[i].h, c = a[i].w;
        while (a[i].w == c) {
            m = max (a[i].h, m);
            i++;
        }
        sum += m;
    }
    cout << sum;


    return 0;
}
