#include <iostream>
using namespace std;

int main() {
    int n,s,a,p,v;
    cin >> n;
    s = n/48;
    n %= 48;
    a = n/16;
    n %= 16;
    p = n/4;
    n %= 4;
    v = n;
    cout << s << " " << a << " " << p << " " << v;

    return 0;
}
