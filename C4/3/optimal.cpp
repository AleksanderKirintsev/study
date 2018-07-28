#include <iostream>

using namespace std;

int main()
{
    int m2 = 0, m7 = 0, m14 = -1, max = 0, a, n;
    cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        cin >> a;

        if ( a % 2 == 0 && a % 7 > 0 && a > m2 )
            m2 = a;

        if ( a % 7 == 0 && a % 2 > 0 && a > m7 )
            m7 = a;

        if ( a % 14 == 0 && a > m14 )
        {
            if ( m14 > max )
                max = m14;

            m14 = a;
        }else if ( a > max )
            max = a;
    }
    cout << ( m2 * m7 < m14 * max ? m14 * max : m2 * m7 );
    return 0;
}
