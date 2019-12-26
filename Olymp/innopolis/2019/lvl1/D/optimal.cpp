#include <iostream>
#include <map>
using namespace std;
#define ll long long
#define X first
#define Y second
#define f(i,j) f[(i)*(s+1)+(j)]
const ll LIM = 1e17;
int n,*a,v,s;
ll *f;

pair<ll,int> g(int i,int j) {
    //cout << i << " " << j << " " << h << "\n";
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
    freopen("tests/00","r",stdin);
    cin >> n >> s >> v;
    a = new int[n] {};
    f = new ll[n*(s+1)];
    for(int i = 0; i < n-1; i++)
        cin >> a[i];

    f(n,0) = 0;
    for(int i = n-1; i >= 0; i--)
        for(int j = 0; j <= s; j++)
            f(i,j) = g(i,j).X;
    ll mn = 0;
    cout << f(0,s);



    return 0;
}
