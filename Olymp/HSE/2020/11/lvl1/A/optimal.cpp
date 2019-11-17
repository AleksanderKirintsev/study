#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define K first
#define V second

int n,k,*s;

multiset<pair<int,vector<int>>> ss;
int main() {
    cin >> n >> k;
    s = new int[k];
    for(int i = 0; i < k; i++)
        cin >> s[i];

    for(int i = 0; i < n; i++) {
        int r,t,x;
        vector<int> a;
        cin >> r >> t;
        for(int i = 0; i < t; i++) {
            cin >> x;
            a.push_back(x);
        }
        ss.insert({r,a});
    }
    for(auto x:ss){
        int f = 1;
        for(auto y : x.V){
            if(s[y-1] != 0){
                cout << y << " ";
                f = 0;
                break;
            }
        }
        if(f) cout << -1 << " ";
    }
    return 0;
}
