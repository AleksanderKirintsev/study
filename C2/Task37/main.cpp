#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand ( time ( NULL ) );
    const int N = 30;
    int a[N];
    int l = 1, lMax = 0, sum = 0, max_sum = 0;

    for ( int i = 0; i < N; ++i )
        a[i] = 1 + rand() % 10; // случайные числа от 1 до 10

    for ( int i = 0; i < N; ++i )
        cout << a[i] << " ";
    cout << endl;

    for ( int i = 0; i < N - 1; ++i )
        if ( a[i] < a[i + 1] )
        {

            l++;
            sum += a[i];

        }
        else
        {
            sum += a[i];
            if ( l == lMax && sum > max_sum )
            {
                max_sum = sum;
            }
            else if ( l > lMax )
            {
                lMax = l;
                max_sum = sum;
            }

            sum = 0;
            l = 1;
        }
    cout << max_sum;
    return 0;
}
