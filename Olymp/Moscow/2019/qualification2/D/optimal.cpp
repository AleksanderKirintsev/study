#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,*a,*b;

int find_place(int num) {
    int l = 0, r = k;
    while(l+1 < r) {
        int mid = (l+r)/2;
        if(b[mid] <= num)
            l = mid;
        else
            r = mid;
    }

    return l;
}

int main() {
    //freopen("tests/00","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> k;

    a = new int[n];
    b = new int[k];

    for(int i = 0; i < n; i++)
        cin >> a[i];
//    for(int i = 0; i < k; i++)
//        b[i] = a[i];
    memcpy(b,a,sizeof(int)*k);
    sort(b,b+k);

    for(int i = k; i < n; i++) {
        cout << b[k/2] << " ";

        int del_idx = find_place(a[i-k]), ins_idx = find_place(a[i]);
        if(del_idx > ins_idx) {
            del_idx += -1;
            memcpy(b+ins_idx+1,b+ins_idx,sizeof(int)*(del_idx-ins_idx+1));
            ins_idx+=(b[ins_idx] < a[i]);
        }else if(del_idx < ins_idx) {
            del_idx += 1;
            memcpy(b+del_idx-1,b+del_idx,sizeof(int)*(ins_idx-del_idx+1));
        }

        b[ins_idx] = a[i];

    }

    cout << b[k/2] << " ";
    return 0;
}
