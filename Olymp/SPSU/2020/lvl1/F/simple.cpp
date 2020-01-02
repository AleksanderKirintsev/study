#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
long long n,p,x,a[100];
bool f(long long sum, int i){
    if(i == n || sum == x)
        return sum == x;
    if(f((sum*a[i])%p,i+1)){
        cout << a[i] << " ";
        return 1;
    }
    if(f((sum*a[i])%p,i+1))
        return 1;
    return 0;
}

int main() {
    cin >> n >> p >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bool b = f(1,0);
    return 0;
}
