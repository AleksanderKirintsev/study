#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k,*s;
vector<int> *a;
struct cmp{
    bool operator()(const vector<int> &l,const vector<int> &r){
        return(l[0] < r[0]);
    }
};
int main() {
    cin >> n >> k;
    s = new int[k];
    a = new vector<int>[n];
    int ans[n];

    for(int i = 0; i < k; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++){
        int r,t,x;
        cin >> r >> t;
        a[i].resize(t+2);
        a[i][0] = r;
        a[i][1] = i;
        for(int j = 2; j < a[i].size(); j++){
            cin >> x;
            a[i][j] = x-1;
        }
    }

    sort(a,a+n,cmp());

    for(int i = 0; i < n; i++){
        bool f = 1;
        for(int j = 2; j < a[i].size(); j++)
            if(s[a[i][j]] > 0){
                ans[a[i][1]] = a[i][j]+1;
                s[a[i][j]]--;
                f = 0;
                break;
            }
        ans[a[i][1]] = (f ? -1 : ans[a[i][1]]);
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
