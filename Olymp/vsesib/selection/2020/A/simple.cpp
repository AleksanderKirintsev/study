#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll n,k,t,r,*a;
string s,tmp1,tmp2;
bool F(ll &a, ll &b, ll &c, ll x){
    if(x <= c){
        c-=x;
    }else{
        x-=c;
        a -= x/b+(x%b > 0);
        c = b-(x%b);
    }
    return (a >= 0);
}
int main() {
    cin >> n >> k >> t;
    a = new ll[n];
    for(ll i = 0; i < n; i++) {
        cin >> s;
        tmp1 = "",tmp2 = "";
        for(ll j = 0; j < 3; j++) {
            tmp1+=s[j];
            tmp2+=s[j+4];
        }
        a[i] = stoi(tmp1) * stoi(tmp2);

    }

    sort(a,a+n);
    if(t > k)
        swap(t,k);

    ll q = 0;
    for(ll i = 0; i < n && t >= 0; i++){
        q += F(t,k,r,a[i]);
    }
    cout << q;
    return 0;
}
