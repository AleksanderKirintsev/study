#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    srand ( time ( NULL ) );

    int answer;

    for ( int j = 0; j < 5; j++ )
    {
        string g;
        switch ( j )
        {
        case 0:
            g += "0";
            break;
        case 1:
            g += "1";
            break;
        case 2:
            g += "2";
            break;
        case 3:
            g += "3";
            break;
        case 4:
            g += "4";
            break;
        }

        ofstream input ( "tests\\0" + g );
        ofstream output ( "tests\\0" + g + ".a" );

        int N;
        N = rand() % 6 + 5;

        cout << "N = " << N << endl;
        input << N << endl;

        int a[N];

        for ( int i = 0; i < N; i++ )
        {
            a[i] = 1 + rand() % 20;

            cout << a[i] << " ";
            input << a[i] << " ";
        }

        cout << endl << "answer: ";
        cin >> answer;
        output << answer;

        input.close();
        output.close();
    }
    return 0;
}
