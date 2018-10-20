#include <iostream>
using namespace std;
#define ll long long

long long int n, m;
int a, b;

ll simple() {
    if ( n >= m )
        return 0;

    ll x = m - n, y = 0, s = a * x,zero = 0;

    do {
        x = max ( x - 4, zero);
        y++;
        s = min ( a * x + b * y, s );
    } while ( x > 0 );

    return s;
}

int main() {
    cin >> n >> m >> a >> b;
    cout << simple();

    return 0;
}
