#include <iostream>

using namespace std;
long long int n, m;
int a, b;

int optimal() {
    long long int q1 = 0, q2 = 0;
    if ( n >= m )
        return 0;
    else if ( b >= a * 4 )
        return ( m - n ) * a;
    else {
        q2 = ( m - n ) / 4;
        m = m - q2 * 4 - n;

        if ( a * m > b )
            q2++;
        else
            q1 = m;
        return q2 * b + q1 * a;
    }
}

int main() {

    cin >> n >> m >> a >> b;
    cout << optimal();
    return 0;
}
