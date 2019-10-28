#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define ll long long
int n,*mark,md;
vector<vector<int>> g;

void dfs(int v,int d){
    mark[v] = 1;
    md = max(md,d);
    for(auto x:g[v])
        if(!mark[x])
            dfs(x,d+1);
}

int main() {
    cin >> n;
    g.resize(n);
    mark = new int[n];
    for(int i = 0,x,y; i < n-1; i++){
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    ll idx,ms = 1e18;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        mark = new int[n]{};
        mark[i] = 1,md = 0;
        for(auto v: g[i]){
            dfs(v,0);
            sum+=(md+1)*(md+1);
        }
        if(ms > sum){
            ms = sum;
            idx = i;
        }
        delete mark;
    }
    cout  << ms << " " <<  idx+1;
    return 0;
}
