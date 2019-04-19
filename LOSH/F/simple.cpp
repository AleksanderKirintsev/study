#include <iostream>

using namespace std;

int main() {
    long long p = 0,n = 0,a,q;

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a;
        if (a >= 0)
            p++;
        else
            n++;
    }
    cout << n*n + p*n-n;
    return 0;
}
