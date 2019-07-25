#include <iostream>
#include <algorithm>
using namespace std;
int n,*a;
int main() {
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a,a+n);
    int l = n/2-!(n%2);
    int r = l+1;
    while( 0 <= l || r < n)
        cout << a[(l+1 < n-r ? r++ : l--)] << " ";

    return 0;
}
