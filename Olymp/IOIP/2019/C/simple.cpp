#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define ll long long

int MOD = 1e9+7;

string s;
int *a, n;

inline int process(int x, int d){
    if(100 <= x && x <= 122)
        return 1;
    int a = x/100, b = (x/10)%10, c = x % 10, q = 0;
    set<int> ss;
    ss.insert(a == d ? b*10+c : 0);
    ss.insert(b == d ? a*10+c : 0);
    ss.insert(c == d ? a*10+b : 0);
    for(int i : ss)
        q += (isalpha(i) > 0);
    return q;
}
int main() {
//    freopen("tests/19","r",stdin);
    cin >> s;
    a = new int[n = s.size()/3];
    for(int i = 0,j = 0; i < n; i++,j+=3)
        a[i] = stoi(s.substr(j,3));

    int k = 0;
    for(int i = 0; i < n; i++)
        k += (100 <= a[i] && a[i] <= 122);

    if(k == n){
        cout << 1;
        return 0;
    }
    ll ans = 0;
    for(int d = 0; d <= 9; d++){
        ll q = 1;
        for(int i = 0; i < n && q > 0 ; i++){
            q *= process(a[i],d);
            q %= MOD;
        }
        ans += q;
    }

    cout << ans % MOD;
    return 0;
}
