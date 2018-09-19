#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
#define ALIM 20
#define NLIM 10
int main() {
    srand ( time ( NULL ) );

    int a[20], n;
    n = 1 + rand() % NLIM;

    for ( int i = 0; i < n; i++ ) {
        a[i] = rand() % ( ALIM + 1 );
        cout << a[i] << " ";
    }
    cout << endl;

    for ( int i = 0; i < n - 1; i++ ) {
        int m = 20, num;
        for ( int j = i; j < n; j++ ) {
            if ( m > a[j] ) {
                m = a[j];
                num = j;
            }
        }
        swap ( a[i], a[num] );
    }

    for ( int i = 0; i < n; i++ )
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
