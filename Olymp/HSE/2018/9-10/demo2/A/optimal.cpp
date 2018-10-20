#include <iostream>

using namespace std;
struct Time {
    int h, m, s;
};
istream& operator>> ( istream& is, Time& t ) {
    char c;
    cin >> t.h >> c >> t.m >> c >> t.s;
}
bool operator<= ( Time& l, Time& r ) {
    return ! ( ( l.h > r.h ) || ( ( l.h == r.h ) && ( l.m > r.m ) ) || ( ( l.h == r.h ) && ( l.m == r.m ) && ( l.s > r.s ) ) ) ;
}

int main() {
    cin.tie ( 0 );
    cin.sync_with_stdio ( 0 );
    cout.tie ( 0 );
    int days = 1, n;
    Time prev, curr;

    cin >> n;
    cin >> prev;

    for ( int i = 1; i < n; i++ ) {
        cin >> curr;
        if ( curr <= prev )
            days++;
        prev = curr;

    }
    cout << days;
    return 0;
}
