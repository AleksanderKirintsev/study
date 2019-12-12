#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define X first
#define Y second

int n,k;
vector<int> a,b;

pair<ll,int> g(int i, int j, int h);
ll f(int i, int j, int h){
    return g(i, j, h).X;
}
pair<ll,int> g(int i, int j, int h){
    if (j == 0)
        return {0,0};
    set<pair<ll,int>> s = {};
    if (n - i > j)
        s.insert({f(i+1, j  , 0)                , 0});
    if (n - i > j && h != 1)
        s.insert({f(i+1, j-1, 1) + b[i] + b[i+1], 1});
    if (n - i > j && h != 2)
        s.insert({f(i+1, j-1, 2) + a[i] + a[i+1], 2});
    if (h != 1 && h != 2)
        s.insert({f(i+1, j-1, 3) + a[i] + b[i]  , 3});
    return *(--s.end());
}
int main() {
    //freopen("tests/03","r",stdin);
    cin >> n >> k;
    a.resize(n), b.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector<pair<int,int>> v;
    v.resize(n,{0,0});
    for(int i = 0, j = k, h = 0; j > 0; i++){
        switch(h = g(i,j,h).Y){
        case 1:v[i].Y = v[i+1].Y = k-(--j);break;
        case 2:v[i].X = v[i+1].X = k-(--j);break;
        case 3:v[i].X = v[i].Y   = k-(--j);break;

        }
    }

    for(int i = 0; i < n; i++)
        cout << v[i].X << " " << v[i].Y << "\n";

    return 0;
}
