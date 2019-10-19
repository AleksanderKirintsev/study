#include <iostream>
#include <vector>
using namespace std;
int n,*v,*mark;
vector<vector<int>> g;
void dfs(int v){
    mark[v] = 1;
    for(auto x:g[v])
        if(!mark[x])
            dfs(x);

}
int main() {
    cin >> n;
    v = new int[n]{};
    mark = new int[n]{};
    g.resize(n);
    for(int i = 0,a; i < n; i++){
        cin >> a;
        v[a-1]++;
        g[i].push_back(a-1);
    }
    int q = 0;
    for(int i = 0; i < n; i++)
        if(v[i] == 0){
            dfs(i);
            q++;
        }
    for(int i = 0; i < n; i++)
        if(!mark[i]){
            dfs(i);
            q++;
        }
    cout << q;
    return 0;
}
