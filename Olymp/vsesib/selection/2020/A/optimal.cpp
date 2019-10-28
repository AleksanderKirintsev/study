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

    ll q = 0,a = min(t,k),b = max(t,k),c = 0;
    for(int i = 0; i < n; i++) {
        c-=data[i];
        if(c < 0){
            a-= (-c)/b+((-c)%b > 0);
            c = b-((-c)%b);
        }
        if(a < 0)
            break;
        q++;
    }
    cout << q;
    return 0;
}
