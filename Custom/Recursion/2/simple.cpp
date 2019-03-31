#include <iostream>

using namespace std;

int f(int n,int k) {
    if (n == 0)
        return 1;
    else if(k == 0)
        return 0;

    int sum = 0;
    for(int i = min(n,k); i > 0; --i)
        sum += f(n-i,i-1);

    return sum;
}
int main() {
    int n;
    cin >> n;
    cout << f(n,n);
    return 0;
}
