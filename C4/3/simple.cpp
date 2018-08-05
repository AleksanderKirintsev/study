#include <iostream>

using namespace std;

int main()
{
    int n;
    int max = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for ( int i = 0; i < n - 1; i++ )
        for ( int j = i + 1; j < n ; j++ )
            if ( a[i] * a[j] % 14 == 0 && a[i] * a[j] > max )
                max = a[i] * a[j];
    cout << max;

    return 0;
}
