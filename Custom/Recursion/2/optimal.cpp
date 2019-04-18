#include <iostream>
using namespace std;

int f(int n,int k) {
    int sum = (n <= k);

    for(int i = min(n,k) - sum; n-i <= (i*i-i)/2; --i)
        sum += f(n-i,i-1);
    return sum;
}
int main() {
    //freopen("tests//02","r",stdin);
    int n;
    cin >> n;
    cout << f(n,n);
    return 0;
}

