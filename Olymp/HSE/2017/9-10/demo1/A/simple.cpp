#include <iostream>

using namespace std;

int main() {
    long long int n, m, sum = 0, min_sum = 1e18, y, x;
    int a, b;
    cin >> n >> m >> a >> b;

    for ( x = 0, y = abs( n - m ) / 4 + 1; y >= 0; x += 4,y -= 1 ) {
       sum = x * a + y * b;

        if (sum < min_sum &&sum > 0 )
            min_sum = sum;
    }

    for ( y = 0, x = abs( n - m ); x >= 0; y++, x -= 4 ) {
       sum = x * a + y * b;

        if (sum < min_sum && sum > 0 )
            min_sum = sum;
    }
    cout << min_sum;

    return 0;
}
