#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]
ll n,m,p,*a,*b;

void transpose(){
    ll *tmp = new ll[(n+2)*(m+2)]{};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            tmp[j*(n+2)+i] = a(i,j);
    delete a;
    a = tmp;
    swap(n,m);
}

inline ll find_solution(ll ceil, ll floor){
    ll ans = -1;
    map<int,ll[2]> mp;
    for(int i = 1; i <= m; i++){
        ll s = b(ceil,i) - b((floor-1),i);
        if(s % p == 0)
            ans = max(ans,s);
        else{
            auto it = mp[s%p];
            int f = 1;
            if(it[0] == 0 && it[1] == 0){
                it[0] =1e18;
                it[1] =-1;
                f = 0;
            }
            it[0] = min(s,it[0]);
            it[1] = max(s,it[1]);
            ans = max(ans,(f ? it[1]-it[0] : -1));
        }
    }
    return ans;
}

int main() {
    //freopen("check/22","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> m >> p;
    a = new ll[(n+2)*(m+2)]{};
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            cin >> a(i,j);

    if(n > m)
        transpose();

    b = new ll[(n+2)*(m+2)]{};

    for(ll i = 1; i <= n; i++)
        for(ll j = 1,t = 0; j <= m; j++)
            b(i,j) = (t+=a(i,j))+b((i-1),j);

    ll ans = -1,r = 0;
    for(int i = n; i >= 1; i--)
        for(int j = 1; i-j >= r; j++){
            ll sum = find_solution(i,j);
            r = (sum > ans ? i-j : r);
            ans = max(ans,sum);
        }

    cout << ans;
    return 0;
}
