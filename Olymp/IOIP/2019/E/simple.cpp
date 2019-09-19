#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define ll long long
ll const MOD = 998244353;
int n,q,f,*used,j = 1;
vector<int> s;
vector<vector<int>> g;
int bs[3];
inline bool check() {
    for(auto x : g[s[s.size()-1]])
        if(bs[x] == 0)
            return 0;
    return 1;
}

inline int bs_find_first(){
    while(bs[j%n] == 1 && s.size() != n)
        j++;
    j%=n;
    return j;
}

int main() {
    freopen("check/01","r",stdin);
//    freopen("answer","w",stdout);
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;
        g[b-1].push_back(a-1);
    }
    s.push_back(0);
    while(s[0] != n-1 || !f) {
        if(bs[s.back()] == 0 && check()){
            f = 0;
        }else
            f = 1;
        bs[s.back()] = 1;
        if(s.size() == n){
            q++;
            f = 1;
        }
        if(f == 1 && s.back() != n-1){
            bs[s.back()] = 0;
            s[s.size()-1]++:
            bs[s.back()] = 1;
        }

    }
    cout << q;
    return 0;
}
