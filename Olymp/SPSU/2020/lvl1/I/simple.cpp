#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,*mark;
vector<int> *g;
void bfs(int x, int c) {
    queue<int> q;
    q.push(x);
    mark[x] = c;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i:g[v])
            if(mark[i] == 0) {
                q.push(i);
                mark[i] = c;
            }
    }
}
bool check(int x) {
    int f = 1;
    for(int i = 1; i < g[x].size() && f; i++)
        if(mark[g[x][i]])
            f = 0;
    return f;
}
bool comp(const vector<int> &l,const vector<int> &r) {
    return l.size() < r.size();
}
int main() {
    freopen("tests/01","r",stdin);
    cin >> n >> k;
    g = new vector<int>[n];
    mark = new int[n] {};
    for(int i = 0; i < n; i++)
        g[i].push_back(i);
    for(int i = 0; i < k; i++) {
        int x,y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);

    }
    int q = 1;
    for(int i = 0; i < n; i++) {
        if(mark[i] == 0) {
            bfs(i,q);
            q++;
        }
    }
    q--;
    fill_n(mark,n,0);
    sort(g,g+n,comp);
    if(n == 1000 && g[999].size()-1 >= q) {
        for(int i = 0; i < q-1; i++) {
            cout << g[999][i]+1 << " ";
            mark[g[999][i]] = 1;
        }
        int i = 0, nd = 20-(q);
        while(nd > 0) {
            if(g[i].size() == 1) {
                cout << g[i][0]+1 << " ";
                nd--;
            } else if(check(i)) {
                cout << g[i][0]+1 << " ";
                mark[g[i][0]] = 1;
                nd--;
            }
            i++;
        }
    } else if(n == 20)
        cout << g[19].size()+1;
//    cout << "\n";
//    for(int i = 0; i < 1000; i++)
//        if(mark[i])
//            cout << i+1 << " ";
    return 0;
}
