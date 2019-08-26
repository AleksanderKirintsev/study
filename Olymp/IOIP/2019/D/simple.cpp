#include <iostream>
using namespace std;
#define ll long long
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]
ll n,m,p,*a;

int main() {
    cin >> n >> m >> p;
    a = new ll[(n+2)*(m+2)]{};

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            cin >> a(i,j);

    ll *b = new ll[(n+2)*(m+2)]{};
    for(ll i = 1; i <= n; i++)
        for(ll j = 1,t = 0; j <= m; j++)
            b(i,j) = (t+=a(i,j))+b((i-1),j);

    ll ans = 0;
    for(int x0 = 1; x0 <= n; x0++)
        for(int x1 = x0; x1 <= n; x1++)
            for(int y0 = 1; y0 <= m; y0++)
                for(int y1 = y0; y1 <= m; y1++){
                    ll sum = b(x1,y1)-b(x1,(y0-1))-b((x0-1),y1)+b((x0-1),(y0-1));
                    ans = max(ans,(sum % p ? 0 : sum));
                }
    cout << ans;
    return 0;
}
