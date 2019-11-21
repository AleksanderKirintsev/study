#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,*r,*s,*t;
vector<vector<int>> g;
pair<int,int> F(int a, int *r) {
    queue<int> q;
    q.push(a);
    r[a] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x: g[v]) {
            if(!r[x]) {
                r[x] = r[v]+1;
                q.push(x);
            }
            if(r[x] == r[a])
                return{x,a};
        }
    }
    return {-1,-1};
}
vector<int> G(int s, int f) {
    queue<int> q;
    int *p = new int[n] {};
    vector<int> way;
    p[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x:g[v])
            if(!p[x]) {
                p[x] = p[v]+1;
                q.push(x);
            }

    }
    int curr = f;
    way.push_back(curr);
    for(int x : g[curr]) {
        if(curr == x)
            return way;
        if(p[x] < p[curr]) {
            way.push_back(curr);
            curr = x;
        }
    }

}
return way;
}
int main() {
    cin >> n >> m;
    g.resize(n);
    vector<int> ans;
    r = new int[n] {};
    s = new int[n] {};
    t = new int[n] {};
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    for(int i = 0; i < n; i++)
        if(!r[i]) {
            pair<int,int> p = F(i,r);
            if(p != {-1,-1}) {
                F(p.first,s);
                F(p.second,t);
                int mn = 1e9,idx = -1;
                for(int i = 0; i < n; i++)
                    if(s[i] && s[i] == f[i] && s[i] < mn) {
                        mn = s[i];
                        idx = i;
                    }

            }
        }

    return 0;
}
