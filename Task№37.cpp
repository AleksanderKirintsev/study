#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    const int N = 30;
    int a[N];
    int l=1,lmax=0,s = 0,smax = 0;

    for (int i = 0; i < N; ++i)
        a[i] = 1 + rand()%10; // случайные числа от 1 до 10

    for (int i = 0; i < N; ++i)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 0; i < N-1; ++i)
        if(a[i] < a[i+1])
        {

            l++;
            s += a[i];

        }else
        {
            s += a[i];
            if(l == lmax && s > smax )
            {
                smax = s;
            }else
                if (l > lmax)
                {
                    lmax = l;
                    smax = s;
                }

            s = 0;
            l = 1;
        }
    cout << smax;
    return 0;
}
