#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int n,k,a[1000010];
int main(){
	//freopen("tests/100","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0,r = k;

    for (int i = 0; i < n - k + 1; i++){
        multiset<int> ms(a+l,a+r);
        auto iter = ms.begin();
        advance(iter,k/2);
        cout << *iter << " ";
        l++; r++;
    }
    return 0;
}
