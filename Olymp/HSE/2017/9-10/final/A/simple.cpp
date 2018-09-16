#include <iostream>

using namespace std;

int main() {
    short int N, M, a[10000], l_max_t, min_t, max = 0, ans, num = 0;
    cin >> N >> M;


    for ( int i = 0; i < M; i++ ) {
        cin >> a[i];
    }

    for ( int i = 1; i <= N; i++ ) {
        num = 0;
        for ( int j = 0; j < M; j++ ) {
            if ( a[j] == i ) {
                num++;
                l_max_t = j;
            }
        }
        //cout << l_max_t << " " << min_t << " " << i << endl;
        if ( num > max ) {
            max = num;
            min_t = l_max_t;
            ans = i;
        }
        if ( num == max && l_max_t < min_t )
            ans = i;
    }

    cout << ans;
    return 0;
}
