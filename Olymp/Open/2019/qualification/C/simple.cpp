#include <iostream>
#include <algorithm>
using namespace std;
#define F first
#define S second
int main(){
    long long int n,p,k,m,sum = 0;
    cin >> n >> p >> k;
    pair<int,int> a[n];

    for (int i = 0; i < n; i++){
        cin >> m;
        a[i].F = m / k;
        a[i].S = m % k;
    }
    sort (a, a + n, [](const pair<int,int> &l, const pair<int,int> &r) {return l > r;});

    for(int i = 0; i < n; i++){
        if (p - (k - a[i].S) >= 0){
            p -=(k - a[i].S);
            a[i].S+=k-a[i].S;

            a[i].F += a[i].S / k;
            a[i].S = a[i].S % k;
        }else break;
    }

    for (int i = 0; i < n; i++)
        sum+=a[i].F;
    cout << sum + p / k;
    return 0;
}
