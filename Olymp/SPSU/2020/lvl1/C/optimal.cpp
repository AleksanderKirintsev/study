#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define X first
#define Y second

int k,n,m,u,v,l,*a,*mark,*dst;
vector<vector<pair<int,int>>> g;
map<int,vector<int>> gr;

void d(int x){
    set<pair<int,int>> s;
    s.insert({0,x});
    while(!s.empty()){
        pair<int,int> p = *(s.begin());
        for(auto i:g[p.Y])
            if(i.Y + p.X <= k && dst[i.X] > i.Y + p.X && !mark[i.X]){
                dst[i.X] = i.Y + p.X;
                s.insert({dst[i.X],i.X});
            }
        mark[p.Y] = 1;
        s.erase(s.begin());

    }
}

void make_ways(int x){
    fill_n(dst,n,1e9);
    fill_n(mark,n,0);

    d(x);

    for(int i = 0; i < l; i++)
        if(dst[a[i]-1] != 1e9 && a[i] != x)
            gr[x].push_back(a[i]-1);
    if(dst[v-1] != 1e9)
        gr[x].push_back(v-1);

    fill_n(dst,n,1e9);
    fill_n(mark,n,0);

}

void bfs(int x){
    fill_n(dst,n,0);
    fill_n(mark,n,0);

    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto i:gr[p])
            if(!mark[i]){
                dst[i] = dst[p]+1;
                q.push(i);
            }
    }
}

int  main() {
    cin >> k >> n >> m >> u >> v;
    g.resize(n);
    dst = new int[n];
    mark = new int[n];
    for(int i = 0; i < m; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if(z <= k){
            g[x-1].push_back({y-1,z});
            g[y-1].push_back({x-1,z});
        }
    }
    cin >> l;
    a = new int[l];
    int q1 = 1,q2 = 1;
    for(int i = 0; i < l; i++){
        cin >> a[i];
        q1 = (a[i] == u ? 0 : q1);
        q2 = (a[i] == v ? 0 : q2);
    }


    if(q1)
        make_ways(u-1);
    if(q2)
        make_ways(v-1);

    for(int i = 0; i < l; i++)
        make_ways(a[i]-1);

    bfs(u-1);
    cout << dst[v-1]-1;
    return 0;
}
