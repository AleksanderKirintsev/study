#include <iostream>

using namespace std;
long long int n, m;
int a, b;

int simple() {
    if ( n >= m )
        return 0;
    int x = m - n, y = 0, s = a * x;
    do {
        x = max ( x - 4, 0 );
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
