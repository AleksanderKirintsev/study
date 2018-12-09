#include <iostream>
#include <bitset>
using namespace std;

unsigned int n,q,a[500001];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n+1; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++) {
        char c;
        int l,r;

        cin >> c >> l >> r;

        if(c == '?') {
            unsigned long long int b[2] = {0};
            for(int j = l; j <= r; j++) {
                b[a[j]/64] |= ((unsigned long long)(1 << a[j] % 64));
                printf("%2d %2d ",j,a[j]);
                cout << bitset<sizeof (long long)* 8>(*(long long int*)(&b[0])) << " " << b[0] <<endl;
            }


            int j;
            for(j = 0; b[j] == (1<<64);)
                j++;

            for (int d = 0; d < 64; d++)
                if ((b[j] & (1 << d)) == 0) {
                    cout << j*64+d << '\n';
                    break;
                }
        } else
            a[l] = r;
    }
    return 0;
}
