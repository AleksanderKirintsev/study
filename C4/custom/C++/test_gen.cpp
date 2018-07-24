#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    srand ( time ( NULL ) );


    const int N = 10;
    int a[N];
    int otvet;
    for ( int j = 0; j < 5; j++ )
    {
        string g;
        g += "0";
        g += to_string ( j );

        ofstream vvod ( "tests\\" + g );
        ofstream answer ( "tests\\" + g + ".a" );

        for ( int i = 0; i < N; i++ )
        {
            a[i] = rand() % 10;
            cout << a[i] << " ";
            vvod << a[i] << " ";
        }

        cout << endl << "otvet: ";
        cin >> otvet;
        answer << otvet;

        cout << endl << endl;
        vvod.close();
        answer.close();
    }
    return 0;
}
