#include <iostream>

using namespace std;

int f(int n,int k) {
    if (n == 0)
        return 1;

    int sum = 0;
    for(int i = n; i > n/2; --i)
        sum += f(n-i,i-1);

    return sum;
}
int main() {
    int n;
    cin >> n;
    cout << f(n,n+1);
    return 0;
}
