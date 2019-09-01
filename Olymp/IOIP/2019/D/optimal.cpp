#include <iostream>
#include <map>
#include <deque>
using namespace std;
#define ll long long
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]
ll n,m,p,*a,*b,r,d,h;

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
    ll ans = -1,mn,mx;
    map<ll,ll[2]> mp;
    for(int i = 1,j = m; i <= m/2; i++,j--){
        ll s = b(ceil,i) - b((floor-1),i);
        ll s1 = b(ceil,j) - b((floor-1),j);
        auto it = mp[s%p],it1 = mp[s1%p];
        if(s1-s < ans)
            return ans;
        if(it[0] == 0 && it[1] == 0){
            it[0] = 1e18;
            it[1] = -1;
        }
        if(it1[0] == 0 && it1[1] == 0){
            it1[0] = 1e18;
            it1[1] = -1;
        }

        if(s % p == 0)
            ans = max(ans,s);
        if(it[0] != 1e18)
            it[1] = max(it[1],s);
        it[0] = min(it[0],s);
        if(it[1]-it[0] > ans){
            ans = it[1]-it[0];
            mn = it[0];
            mx = it[1];
        }


        if(s1 % p == 0)
            ans = max(ans,s1);
        if(it1[1] != -1)
            it1[0] = min(it1[0],s1);
        it1[1] = max(it1[1],s1);
        if(it1[1]-it1[0] > ans)
            ans = it1[1]-it1[0];

    }
    return ans;
}

void print(){
    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << a(i,j) << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main() {
//    freopen("check/07","r",stdin);
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

    ll ans = -1;
    for(int i = n; i >= 1; i--)
        for(ll c = n, f = n-i+1; f >= 1; c--,f--){
            ll sum = find_solution(c,f);
            ans = max(ans,sum);
        }

    cout << ans;
    return 0;
}
