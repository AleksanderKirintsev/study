#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
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

int optimal() {
    long long int q1 = 0, q2 = 0,tmp = m;
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
            m = tmp;
        return q2 * b + q1 * a;
    }
}

int main() {
    srand ( time ( 0 ) );
    int q = 0;
    for ( int i = 0; i < 100;i++ ) {
        n = 1 + rand() % 20;
        m = 1 + rand() % 20;
        a = 1 + rand () % 100;
        b = 1 + rand () % 100;
        if ( optimal() != simple() ) {
            q++;
            ofstream fout ( "mistakes" );
            fout << n << " " << m << " " << a << " " << b << endl;
            fout << "optimal res = " << optimal() << " simple res = " << simple() << endl;
            fout.close();
        }
    }

    cout << q << " errors";
    return 0;
}
