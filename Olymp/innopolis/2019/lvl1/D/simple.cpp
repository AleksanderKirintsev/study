 #include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define X first
#define Y second
const ll LIM = 1e10;
int n,*a,v,s;

pair<ll,int> g(int i,int j, int h);
ll f(int i,int j, int h){
    return g(i,j,h).X;
}
pair<ll,int> g(int i,int j, int h){
    if(j == 0)
        return {0,0};
    pair<ll,int> sum = {LIM,0};
    ll x = max(0,j-v*(n-i-1));
    ll y = min(v,j);
    for(int q = x; q <= y; q++)
            sum = min(sum,{q*a[i]+f(i+1,j-q,q),q});
    return sum;
}
int main() {
    freopen("tests/00","r",stdin);
    cin >> n >> s >> v;
    a = new int[n];
    for(int i = 0; i < n-1; i++)
        cin >> a[i];

    cout << f(0,s,0) << "\n";
    for(int i = 0,j = s, h = 0; i < n; i++,j-=h){
        h = g(i,j,h).Y;
        cout << h << " ";
    }


    return 0;
}
