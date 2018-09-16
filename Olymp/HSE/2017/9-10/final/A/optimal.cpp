#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    short int N, M, x, min_t = 10001, circle = 0; //10 байт
    short int  num[101], time[101]; //404 байта

    cin >> N >> M;

    for ( short int i = 1; i <= N; i++ ) {
        num[i] = 0;
        time[i] = 0;

    }

    for ( short int i = 0; i < M; i++ ) {
        cin >> x;
        num[x]++;
        time[x] = i;

    }

    for ( short int i = 1; i <= N; i++ ) {
        if (num[i] > circle)
            circle = num[i];

    }

    for ( short int i = 1; i <= N; i++ ) {
        if ( num[i] == circle && time[i] < min_t ) {
            min_t = time[i];
            x = i;

        }
    }

    cout << x;
    return 0;
}
