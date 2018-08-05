#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

int main()
{
    const int TLim = 5,MAXV = 20 ;
    srand ( time ( NULL ) );

    int answer;

    for ( int j = 0; j < TLim; j++ )
    {
        ofstream input ( "tests\\0" + to_string(j));
        ofstream output ( "tests\\0"+ to_string(j) +".a");

        int N;
        N = rand() % 6 + 5;

        cout << "N = " << N << endl;
        input << N << endl;

        int a[N];

        for ( int i = 0; i < N; i++ )
        {
            a[i] = 1 + rand() % MAXV;

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
