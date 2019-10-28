#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n,r,*data;
ll k,t;

int main() {
//    freopen("tests/01","r",stdin);
    cin >> n >> k >> t;
    data = new int[n];
    for(int i = 0; i < n; i++) {
        int x,y;
        char c;
        cin >> x >> c >> y;
        data[i] = x*y;

    }

    sort(data,data+n);
    t*=k;

    int q = 0;
    for(int i = 0; i < n && t > 0; i++,q++) {
        if(t < data[i])
            break;
        t -= data[i];
    }

    cout << q;
    return 0;
}
