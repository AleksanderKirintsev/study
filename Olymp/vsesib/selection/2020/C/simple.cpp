#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define ll long long
int n, md;
vector<vector<int>> g;

void dfs(int v,int d,int p){
    md = max(md,d);
    for(auto x:g[v])
        if(x != p)
            dfs(x,d+1,v);
}

int main() {
    cin >> n;
    g.resize(n);
    for(int i = 0,x,y; i < n-1; i++){
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    ll idx,ms = 1e18;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        md = 0;
        for(auto v: g[i]){
            dfs(v,0,i);
            sum+=(md+1)*(md+1);
        }
        if(ms > sum){
            ms = sum;
            idx = i;
        }
    }
    cout  << ms << " " <<  idx+1;
    return 0;
}
