#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,*a,*b;

int main() {
    //freopen("tests/01","r",stdin);
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

    for(int i = k; i < n; i++) {
        cout << b[k/2] << " ";

        int del_idx = lower_bound(b,b+k,a[i-k])-b, ins_idx = lower_bound(b,b+k,a[i])-b-(a[i] > b[k-1]);
        if(del_idx > ins_idx) {
            memcpy(b+ins_idx+1,b+ins_idx,sizeof(int)*(del_idx-ins_idx));
            ins_idx+=(b[ins_idx] < a[i]);
        }else if(del_idx < ins_idx) {
            memcpy(b+del_idx,b+del_idx+1,sizeof(int)*(ins_idx-del_idx));
            ins_idx-=(b[ins_idx] > a[i]);
        }

        b[ins_idx] = a[i];

    }

    cout << b[k/2] << " ";
    return 0;
}
