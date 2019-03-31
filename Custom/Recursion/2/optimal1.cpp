#include <iostream>
using namespace std;

int f(int n,int k) {
    int sum = 0;
    for(int i = min(n,k); n-i <= (i*i-i)/2; --i)
            sum += (n-i > 0 ? f(n-i,i-1) : 1);
    return sum;
}
int main() {
    //freopen("tests//02","r",stdin);
    int n;
    cin >> n;
    cout << f(n,n);
    return 0;
}


