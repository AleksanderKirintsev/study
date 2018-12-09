#include <iostream>
using namespace std;
int n,q;

int main() {
  //  cin.tie(0);
  //  cin.sync_with_stdio(0);
 //   cout.tie(0);

    cin >> n >> q;

    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int d = 0; d < q; d++) {
        char c;
        int l,r;
        cin >> c >> l >> r;
        l--;

        if(c =='!')
            a[l] = r;
        else {
            for(int i = 0; i < n; i++)
                for(int j = l; j <= r; j++) {
                    if( i == a[j] && j != r)
                        break;
                    else if(j == r) {
                        cout << i << '\n';
                        i = n;
                    }
                }
        }
    }
    return 0;
}

