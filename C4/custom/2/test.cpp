#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int n;
int *a;

int simple()
{
    int m = 0;
    for ( int i = 0; i < n - 1; i++ )
        for ( int j = i + 1; j < n ; j++ )
            if ( a[i] * a[j] % 14 != 0 && a[i] * a[j] > m )
                m = a[i] * a[j];


    return m;
}

int optimal()
{
    int x;
    int m2a = 0; // ћаксимальное число не кратное 2, или 0 если не нашлось
    int m2b = 0; // ¬торой максимум не кратный 2, или 0 если не нашлось
    int m7a = 0; // ћаксимальное число не кратное 7, или 0 если не нашлось
    int m7b = 0; // ¬торой максимум не кратный 7, или 0 если не нашлось
    int ans = 0;

    for ( int i = 0; i < n; i++ )
    {
        x = a[i];

        if (x % 2 != 0){
            if (x > m2a){
                m2b = m2a;
                m2a = x;
            }

            }


























        if ( x % 14 != 0 )
        {





            if ( x % 2 != 0 && m1 < x )
            {
                m2b = m2a;
                m2a = x;
            }
            else if ( x % 2 != 0 && m1 >= x && m2 < x ){
                m2b = x;
                }
            else if ( x % 7 != 0 && m3 < x )
            {
                m4 = m3;
                m3 = x;
            }
            else if ( x % 7 != 0 && m3 >= x && m4 < x )
                m4 = x;
        }
    }

    int m[4] = {m1, m2, m3, m4};
    for ( int i = 0; i < 3; i++ )
        for ( int j = i + 1; j < 4; j++ )
        {
            if ( m[i] * m[j] % 14 != 0 && ans < m[i] * m[j] )
                ans = m[i] * m[j];
        }


    return ans;
}



int main()
{
    //srand ( time ( NULL ) );
    const int NLim = 10;
    const int VLim = 20;
    const int TLim = 100000;
    a = (int*) malloc(NLim * sizeof(int));

    int k = 0;

    for ( int t = 0; t < TLim; t++ )
    {
        n = rand() % (NLim / 2)  + NLim - (NLim / 2) + 1;
        for ( int i = 0; i < n; i++ )
            a[i] = 1 + rand() % VLim;

        if ( optimal() != simple() )
        {
            cout << "Error!" << endl;
            cout << n << endl;

            for ( int i = 0; i < n; i++ )
                cout << a[i] << " ";
            cout << endl;
            cout << simple() << endl;
            cout << optimal() << endl;
            break;
        }

    }

    cout << "Done!";

    return 0;
}
