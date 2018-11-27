#include <iostream>

using namespace std;

int main() {
    int n, p, q,b,c;
    cin >> n >> p >> q;
    b = n - p;
    c = q - 1;
    if(b-c > 0) cout << 1 << " " << p+q-1;
    if(b-c == 0) cout << 1 << " " << n;
    if(b-c < 0) cout << p+q-n << " " << n;
    return 0;
}
