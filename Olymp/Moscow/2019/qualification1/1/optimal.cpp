#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    freopen("tests/**","r",stdin);
    long long int m,w,h,x,y,a = 0,b = 0;
    cin >> m >> x >> y >> w >> h;
    a+=(x % m == 0 ? 0 : 1);
    b+=(y % m == 0 ? 0 : 1);
    a+=((x+w) % m != 0 && a == 0 ? 1 : 0) + w / m;
    b+=((y+h) % m != 0 && b == 0 ? 1 : 0) + h / m;

    cout << a * b;
    return 0;
}


