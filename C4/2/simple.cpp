#include <iostream>

using namespace std;

int main()
{
    int m2 = 200, m = 200, n;
    cin >> n;

    int a[n];
    bool flag = false;

    for ( int i = 0; i < n; i++ )
        cin >> a[i];

    for ( int i = 0; i < n - 1; i++ )
        for ( int j = i + 1; j < n; j++ )
        {
            if ( ( a[i] + a[j] ) % 2 == 0 && ( a[i] + a[j] ) < m2 )
            {
                m2 = a[i] + a[j];
                flag = true;
            }
            if ( ( a[i] + a[j] ) < m )
                m = a[i] + a[j];
        }
    cout << ( flag == true ? m2 : m );

    return 0;
}
