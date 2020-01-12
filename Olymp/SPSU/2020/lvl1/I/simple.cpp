#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,k,*mark;
vector<vector<int>> g;
void bfs(int x, int c){
    queue<int> q;
    q.push(x);
    mark[x] = c;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i:g[v])
        if(mark[i] == 0){
            q.push(i);
            mark[i] = c;
        }
    }
}
int main() {
    //freopen("tests/01","r",stdin);
    cin >> n >> k;
    g.resize(n);
    mark = new int[n]{};
    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    int q = 1;
    for(int i = 0; i < n; i++){
        if(mark[i] == 0){
            bfs(i,q);
            q++;
        }
    }
    cout << q;
    return 0;
}
