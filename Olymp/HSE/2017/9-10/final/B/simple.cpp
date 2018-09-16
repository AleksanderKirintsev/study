#include <iostream>
using namespace std;

int main() {
    int N, A[100000], B[100000];

    cin >> N;
    for ( int i = 0; i < N; i++ )
        cin >> A[i] >> B[i];
    //cout << endl;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            if ( i != j ) {
                if ( A[i] >= A[j] && B[i] <= B[j] ) {
                    A[i] = -1;
                    B[i] = -1;
                    break;
                }

                if ( A[i] <= B[j] && A[i] > A[j] && B[j] < B[i] && A[i] != B[i] ) {
                    A[i] = B[j] + 1;
                } else if ( A[i] <= A[j] && B[i] < B[j] && B[i] > A[j] && A[i] != B[i] ) {
                    A[j] = B[i] + 1;
                }

            }
        }
        cout << A[i]  << " " << B[i] << endl;
    }

    return 0;
}
