#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,k,*a;
int main(){
	//freopen("tests/00","r",stdin);
    cin >> n >> k;
    a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - k + 1; i++){
        int b[k];
        memcpy(b,a+i,k*sizeof(int));
        sort(b,b+k);
        cout << b[k/2] << " ";
    }
    return 0;
}
