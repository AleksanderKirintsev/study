#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n,k,a[1000010];
int main(){
	freopen("tests/10","r",stdin);
//    cin.tie(0);
//    cin.sync_with_stdio(0);
//    cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> ms(a,a+k);
//    for(auto x : ms)
//        cout << x << " ";

    for (int i = k; i < n; i++){
        auto iter = ms.begin();
        auto key = ms.find(a[i-k]);
        advance(iter,k/2);
//        for(auto x : ms)
//            cout << x << " ";
        cout << *iter << " ";
        ms.erase(key);
        ms.insert(a[i+1]);
    }
    return 0;
}
