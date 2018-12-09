#include <iostream>
using namespace std;
int n,q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int d = 0; d < q; d++) {
        char c; int l,r;
        cin >> c >> l >> r;
        l--;

        if(c == '!')
            a[l] = r;
        else {
            int b[n+1] = {0};
            for(int i = l; i < r; i++)
                b[a[i]] = 1;

            for(int i = 0; i <= n; i++)
                if(b[i] == 0) {
                    cout << i << '\n';
                    break;
                }
        }
    }
    return 0;
}

