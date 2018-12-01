#include <iostream>
using namespace std;

int main() {
//    cin.tie(0);
//    cin.sync_with_stdio(0);
//    cout.tie(0);
    int u[500000];
    u[499999] = 123;
    cout << u[499999];
    int n,q,l,r;
    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int o = 0; o < q; o++) {
        char c;
        cin >> c >> l >> r;
        l--;
        r--;
        if(c =='!')
            a[l] = r+1;
        else {
            int s = 0;

            for(int i = l; i <= r; i++) {

                if (a[i] == s) {
                    s++;
                    i = l-1;
                }
                if (i == r) {
                    cout << s << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
