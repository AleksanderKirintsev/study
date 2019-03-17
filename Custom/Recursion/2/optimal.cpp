#include <iostream>

using namespace std;

int f(int n,int k) {
    if (n == 0)
        return 1;

    int sum = 0;
    for(int i = 1; i < k; ++i)
        if(n-i >=0)
            sum += f(n-i,i);

    return sum;
}
int main() {
    int n;
    cin >> n;
    cout << f(n,n+1);
    return 0;
}

