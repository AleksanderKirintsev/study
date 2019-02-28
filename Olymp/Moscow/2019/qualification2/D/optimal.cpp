#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n,k,*a;
int main(){
//	freopen("tests/10","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> k;
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> ms(a,a+k);
        auto iter = ms.begin();
        advance(iter,k/2);

    for (int i = k - 1; i < n; i++){
        auto key = ms.find(a[i-k+1]);
        cout << *iter << " ";
        ms.erase(key);
        ms.insert(a[i+1]);
    }
    return 0;
}
