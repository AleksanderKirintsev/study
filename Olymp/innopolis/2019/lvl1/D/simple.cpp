#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll LIM = 1e16;
int n,*a,v,s;
ll f(int i,int j, int r){
    if(j == 0 || (j == 0 && i == n-2))
        return r;
    if(i == n-2)
        return 1e6;
    ll sum = LIM;
    for(int x = 0; x <= min(v,j); x++)
        if(v*(n-i) >= j-x)
            sum = min(sum,r*x*a[i]+f(i+1,j-x,x));
    return sum;
}
int main() {
    cin >> n >> s >> v;
    a = new int[n];
    for(int i = 0; i < n-1; i++)
        cin >> a[i];

    ll ans = LIM;
    for(int i = 0; i <= min(v,s); i++)
        ans = min(ans,f(0,s-i,i));
    cout << ans;
    return 0;
}
