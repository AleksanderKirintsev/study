#include <iostream>
#include <algorithm>
using namespace std;
#define Q first
#define R second
int main(){
    long long int n,p,k,m,sum = 0;
    cin >> n >> p >> k;
    pair<int,int> a[n];

    for (int i = 0; i < n; i++){
        cin >> m;
        a[i].Q = m / k;
        a[i].R = m % k;
    }
    sort (a, a + n, [](const pair<int,int> &l, const pair<int,int> &r) {return l.R > r.R;});

    for(int i = 0; i < n; i++){
        if (p - (k - a[i].R) >= 0){
            p -=(k - a[i].R);
            a[i].R+=k-a[i].R;

            a[i].Q += a[i].R / k;
            a[i].R = a[i].R % k;
        }else break;
    }

    for (int i = 0; i < n; i++)
        sum+=a[i].Q;
    cout << sum + p / k;
    return 0;
}
