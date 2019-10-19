#include <iostream>
using namespace std;
int n,*a;
int main() {
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int idx = 1,q = 2,mx_st = a[1] - a[0];
    for(int i = 2, k = 2; i < n; i++){
        k = (a[i]-a[i-1] == a[i-1]-a[i-2] ? k+1 : 2);
        if(k > q){
            idx = i-k+2;
            q = k;
            mx_st = a[i]-a[i-1];
        }
        if(k == q && mx_st < a[i]-a[i-1]){
            idx = i-k+2;
            mx_st = a[i]-a[i-1];
        }
    }
    cout << idx << " " << q;
    return 0;
}
