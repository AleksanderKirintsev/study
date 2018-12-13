#include <iostream>
#include <bitset>
using namespace std;

int n,q,*a;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> q;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++) {
        char c;int l,r;
        cin >> c >> l >> r;
        l--;

        if(c == '?') {
            bitset<500001> b;
            for(int j = l; j < r; j++)
                b[a[j]] = 1;

            int j;
            for(j = 0; b[j] == 1; j++);

            cout << j << '\n';
        }
     else
        a[l] = r;
}
return 0;
}

