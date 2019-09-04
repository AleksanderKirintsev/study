#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll const MOD = 998244353;
int n,*used,ans;
vector<vector<int>> g;

void find_pemintations(int v,int d){
    if(d == n){
        ans++;
        ans%=MOD;
    }
    for(auto x:g[v])
        if(used[x] == 0)
            return;

    used[v] = 1;
    for(int i = 0; i < n; i++){
        if(!used[i])
            find_pemintations(i,d+1);
    }
    used[v] = 0;
}
int main() {
    //freopen("check/01","r",stdin);
    cin >> n;
    used = new int[n]{};
    g.resize(n);
    for(int i = 0; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[b-1].push_back(a-1);
    }
    for(int i = 0; i < n; i++)
        find_pemintations(i,1);
    cout << ans;
    return 0;
}
