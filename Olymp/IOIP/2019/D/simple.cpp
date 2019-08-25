#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define ll long long
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]
ll n,m,p,*a,*b,ans;


int main() {
    //freopen("tests/10","r",stdin);
    cin >> n >> m >> p;
    a = new ll[(n+2)*(m+2)]{};
    b = new ll[(n+2)*(m+2)]{};

    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++)
            cin >> a(i,j);
        b(i,1) = a(i,1);
    }

    for(ll i = 1; i <= n; i++)
        for(ll j = 2; j <= m; j++)
            b(i,j) += b(i,(j-1))+a(i,j);
    for(ll i = 2; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            b(i,j) += b((i-1),j);

    for(int x1 = 1; x1 <= n; x1++)
        for(int y1 = 1; y1 <= m; y1++)
            for(int x = x1; x <= n; x++)
                for(int y = y1; y <= m; y++){
                    ll sum = b(x,y)-b(x,(y1-1))-b((x1-1),y);
                    if(sum % p == 0)
                        ans = max(ans,sum);
                }
    cout << ans;
    return 0;
}
