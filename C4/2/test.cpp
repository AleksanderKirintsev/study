#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int n;
int a[10];

int optimal(){
    int m1 = 201, m2 = 201;
    int m3 = 201, m4 = 201;

    for ( int i = 0; i < n; i++ )
    {


        if ( a[i]% 2 == 0 && m1 > a[i])    {
            m2 = m1;
            m1 = a[i];
        }
        else if ( a[i]% 2 == 0 && m1 <= a[i]&& m2 > a[i])
            m2 = a[i];

        if ( a[i]% 2 != 0 && m3 > a[i]){
            m4 = m3;
            m3 = a[i];
        }
        else if ( a[i]% 2 != 0 && m3 <= a[i]&& m4 > a[i])
            m4 = a[i];
    }

    if ( ( m1 == 101 || m2 == 101 ) && ( m3 == 101 || m4 == 101 ) )
        return min ( min ( m1 + m3, m1 + m4 ), min ( m2 + m3, m2 + m4 ) );
    else
        return min ( m1 + m2, m3 + m4 );
}
int simple(){

    int m2 = 201, m = 201;
    bool flag = false;

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
    return ( flag == true ? m2 : m );
}


int main()
{
    srand ( time ( NULL ) );

    const int MAXV = 100, TLim = 100000;
    int k = 0;

    ofstream out("tests\\faileds_tests");

    for ( int i = 0; i < TLim; i++ )
    {
        n = rand() % 6 + 5;

        for ( int i = 0; i < n; i++ )
            a[i] = 1 + rand() % MAXV;
        if ( optimal() != simple() ){
            k++;
            out << endl << "---------------------------------"<< endl;
            out << n << endl;

            for(int i = 0; i < n; i++){
                out << a[i] << " ";
            }
            out << endl << "simple out: " << simple()  << " optimal out: " << optimal();
            out << endl << "---------------------------------"<<endl;
            }

    }

    cout << k << " Errors" << endl;
    cout << "Done!";
    out.close();
    return 0;
}
