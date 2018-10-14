#include <iostream>
using namespace std;

struct Cycler {
    int q, idx, num;
};

bool operator> ( Cycler& l,  Cycler& r ) {
    return ( l.q > r.q ) || ( ( l.q == r.q ) && ( l.idx < r.idx ) );
}

int main() {
    int N, M, a[10000];
    Cycler curr, leader;
    cin >> N >> M ;

    for ( int i = 0; i < M; i++ )
        cin >> a[i];

    leader = {0, 0, 0};
    for ( int i = 1; i <= N; i++ ) {
        curr = {0, 0, i};
        for ( int j = 0; j < M; j++ )
            if ( a[j] == i ) {
                curr.idx = j;
                curr.q++;
            }
        if ( curr > leader )
            leader = curr;
    }

    cout << leader.num;
    return 0;
}
