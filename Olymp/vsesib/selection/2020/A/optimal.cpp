#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int n,r,*data;
ll k,t;

struct rc {
    ll a,b,c;
    rc operator+=(int l) {
        c+=l;
        a+=(c/b);
        c%=b;
        return {a,b,c};
    }
    bool operator <=(rc l) {
        return (a < l.a || (a == l.a && c == l.c));
    }
};

int main() {
    //freopen("tests/01","r",stdin);
    cin >> n >> k >> t;
    data = new int[n];
    for(int i = 0; i < n; i++) {
        int x,y;
        char c;
        cin >> x >> c >> y;
        data[i] = x*y;
    }

    sort(data,data+n);

    ll q = 0;
    rc s = {0,max(k,t),0},abc ={min(k,t),max(k,t),0};
    for(int i = 0; i < n; i++) {
        s+=data[i];
        if(s <= abc)
            q++;
        else
            break;
    }
    cout << q;
    return 0;
}
