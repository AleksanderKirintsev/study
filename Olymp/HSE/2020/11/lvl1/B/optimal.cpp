#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,*mark,*d;
vector<vector<int>> g;

int bfs_1(int v){
    queue<int> q;
    q.push(v);
    int d[n] = {};
    while(!q.empty()){
        v = q.front();
        d[v] = 1;
        q.pop();
        for(int x: g[v]){
            if(mark[x] < mark[v]){
                if(d[x] == 1)
                    return x;
                q.push(x);
            }
        }
    }
    return -1;
}
vector<int> bfs(int v){
    queue<int> q;
    q.push(v);
    vector<int> way;
    mark[v] = 1;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int x: g[v]){
            if(!mark[x]){
                q.push(x);
                mark[x] = mark[v]+1;
            }
            if(mark[x] == mark[v]){
                d = new int[n];
                int st;
                bfs_1(x);
                st = bfs_1(v);
                queue<int> dq;
                v = st;
                dq.push(v);
                while(!dq.empty()){
                    way.push_back(v);
                    dq.pop();
                    for(int x: g[v]){
                        if(mark[x] < mark[v] && d[x] == 1){
                            dq.push(x);
                            v = x;
                            way.push_back(v);
                        }
                    }
                }

                for(int x: g[v])
                    st = (mark[x] == mark[v] ? x : st);
                v = st;
                while(!dq.empty()){
                    way.push_back(v);
                    dq.pop();
                    for(int x: g[v]){
                        if(mark[x] > mark[v] && d[x]){
                            v = x;
                            dq.push(x);
                            way.push_back(v);
                        }
                    }
                }
                delete d;
                break;
            }
        }
    }
    return way;
}
int main() {
    cin >> n >> m;
    g.resize(n);
    vector<int> ans
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
        mark = new int[n];
        fill_n(mark,n,1e9);
    for(int i = 0; i < n; i++){
        if(!mark[i])
            ans = bfs(i);
        if(ans)
    }
    return 0;
}
