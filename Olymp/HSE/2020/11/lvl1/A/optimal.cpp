#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,*s;

struct man{int r,p; vector<int> d;};
man *v;
struct cmp{
    bool operator()(const man &l,const man &r){
        return(l.r < r.r);
    }
};
int main() {
    cin >> n >> k;
    s = new int[k];
    v = new man[n];
    int ans[n];

    for(int i = 0; i < k; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++){
        int t,x;
        cin >> v[i].r >> t;
        v[i].p = i;
        v[i].d.resize(t);
        for(int j = 0; j < t; j++){
            cin >> x;
            v[i].d[j] = x-1;
        }
    }

    sort(v,v+n,cmp());

    for(int i = 0; i < n; i++){
        bool f = 1;
        for(int j = 0; j < v[i].d.size(); j++)
            if(s[v[i].d[j]] > 0){
                ans[v[i].p] = v[i].d[j]+1;
                s[v[i].d[j]]--;
                f = 0;
                break;
            }
        ans[v[i].p] = (f ? -1 : ans[v[i].p]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
