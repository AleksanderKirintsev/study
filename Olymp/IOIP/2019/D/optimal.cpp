#include <iostream>
#include <map>
#include <deque>
using namespace std;
#define ll long long
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]
ll n,m,p,*a,*b,r,d,h,max_sum = -1;

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
    map<ll,ll[2]> mp;
    for(int i = 1,j = m; i <= m/2; i++,j--){
        ll s = b(ceil,i) - b((floor-1),i);
        ll s1 = b(ceil,j) - b((floor-1),j);
        if(s1 < max_sum || s1 < ans)
            return ans;
        if(mp[s%p][0] == 0 && mp[s%p][1] == 0){
            mp[s%p][0] = 1e18;
            mp[s%p][1] = -1;
        }
        if(mp[s1%p][0] == 0 && mp[s1%p][1] == 0){
            mp[s1%p][0] = 1e18;
            mp[s1%p][1] = -1;
        }

        if(s % p == 0)
            ans = max(ans,s);
        if(mp[s%p][0] != 1e18)
            mp[s%p][1] = max(mp[s%p][1],s);
        mp[s%p][0] = min(mp[s%p][0],s);
        if(mp[s%p][1]-mp[s%p][0] > ans)
            ans = mp[s%p][1]-mp[s%p][0];

        if(s1 % p == 0)
            ans = max(ans,s1);
        if(mp[s1%p][1] != -1)
            mp[s1%p][0] = min(mp[s1%p][0],s1);
        mp[s1%p][1] = max(mp[s1%p][1],s1);
        if(mp[s1%p][1]-mp[s1%p][0] > ans)
            ans = mp[s1%p][1]-mp[s1%p][0];

    }
    return ans;
}

void print(int *a){
    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << a(i,j) << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main() {
//    freopen("check/23","r",stdin);
//    freopen("transpose","w",stdout);
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

    for(int i = n; i >= 1; i--)
        for(ll c = n, f = n-i+1; f >= 1; c--,f--){
            ll sum = find_solution(c,f);
            max_sum = max(max_sum,sum);
        }

    cout << max_sum;
    return 0;
}
