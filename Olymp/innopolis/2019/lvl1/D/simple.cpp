#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define X first
#define Y second
const ll LIM = 1e10;
int n,*a,v,s;
map<pair<int,int>,ll> cache;

pair<ll,int> g(int i,int j);
ll f(int i,int j) {
    pair<int,int> p = {i,j};
    return j > 0 ? cache.count(p) > 0 ? cache[p] : cache[p] = g(i,j).X : 0;
}
pair<ll,int> g(int i,int j) {
    if(j == 0)
        return {0,0};
    pair<ll,int> sum = {LIM,0};
    ll x = max(0,j-v*(n-i-1));
    ll y = min(v,j);
    for(int q = x; q <= y; q++)
        sum = min(sum, {q*a[i]+f(i+1,j-q),q});
    return sum;
}
int main() {
    //freopen("tests/00","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> s >> v;
    a = new int[n] {};
    for(int i = 0; i < n-1; i++)
        cin >> a[i];

    cout << f(0,s) << "\n";
    for(int i = 0,j = s, h = 0; i < n; i++,j-=h) {
        h = g(i,j).Y;
        cout << h << " ";
    }


    return 0;
}
