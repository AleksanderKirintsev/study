#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,*a,*b,*p;

int main() {
    //freopen("tests/09","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> k;

    a = new int[n];
    b = new int[k];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    memcpy(b,a,sizeof(int)*k);
    sort(b,b+k);
    memcpy(p,b,sizeof(int)*k);

    cout << b[k/2] << " ";

    for(int i = k; i < n; i++) {
        int del = a[i-k],ins = a[i];
        if(del > ins) {
            int del_idx = lower_bound(b,b+k,del) - b;
            int ins_idx = upper_bound(b,b+k,ins) - b;
            memmove(b+ins_idx+1,b+ins_idx,sizeof(int)*(del_idx-ins_idx));
            b[ins_idx] = ins;
        }else if(del < ins) {
            int del_idx = upper_bound(b,b+k,del) - b - 1;
            int ins_idx = lower_bound(b,b+k,ins) - b - 1;
            memmove(b+del_idx,b+del_idx+1,sizeof(int)*(ins_idx-del_idx));
            b[ins_idx] = ins;
        }
        cout << b[k/2] << " ";

    }

    return 0;
}
