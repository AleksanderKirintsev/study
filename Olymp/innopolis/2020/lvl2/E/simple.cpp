#include <iostream>
#include <map>
using namespace std;
#define X first
#define Y second
#define ll long long
ll n,s;
pair<ll,ll> *c;

struct trio{int i; ll j, h;};
inline int idx(trio t){return t.i * s * 4 + t.j * 4 + t.h;}
bool operator<(const trio&l,const trio&r){return l.i < r.i || (l.i == r.i && l.j < r.j) || (l.i == r.i && l.j == r.j && l.h < r.h);}
map<trio,ll> cache;


pair<ll,ll> g(int i, ll j, ll h);
ll f(int i, ll j, ll h){
   trio t = {i,j,h}; return j > 0 ? cache.count(t) > 0 ? cache[t] : cache[t] = g(i,j,h).X : 0;
}

pair<ll,ll> g(int i, ll j, ll h){
    if(j == 0 || i == n)
        return {0,0};

    pair<ll,ll> mx = {0,0};
    mx = max(mx,{f(i+1,j,0),0});
    for(ll q = c[i].Y; q >= c[i].X; q--)
        if(j - q >= 0)
            mx = max(mx,{f(i+1,j-q,q)+q, q});
    return mx;
}

int main() {
    cin >> n >> s;
    c = new pair<ll,ll>[n];
    for(int i = 0; i < n; i++)
        cin >>c[i].X >> c[i].Y;

    ll ans = g(0,s,0).X;
    cout << ans << "\n";
    for(ll i = 0, j = s, h = 0; i < n; i++,j-=h)
        cout << (h = g(i,j,h).Y) << " ";

    return 0;
}
