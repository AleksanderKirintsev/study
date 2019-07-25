#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int w,n,m,*a,*b,c1,c2;

int count_lines(int l){
    int s = 0;
    c1 = 1,c2 = 1;
    for(int i = 0; i < n; i++){
        if(s+a[i] > l){
            s = a[i]+1;
            c1++;
        }else
            s+= a[i]+1;
    }
    s = 0;
    for(int i = 0; i < m; i++){
        if(s+b[i] > w-l){
            s = b[i]+1;
            c2++;
        }else
            s+= b[i]+1;
    }
    return max(c1,c2);
}
int main() {
    //freopen("tests/02","r",stdin);
    cin >> w >> n >> m;
    a = new int[n];
    b = new int[m];
    int mx1 = 0,mx2 = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx1= max(mx1,a[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        mx2= max(mx2,b[i]);
    }
    int l = mx1-1,r = w-mx2+1,ans = 2e9;
    while(l+1 < r){
        int mid = (l+r)/2;
        ans = min(ans,count_lines(mid));
        if(c1 > c2)
            l = mid;
        else
            r = mid;
    }

    cout << ans;
    return 0;
}
