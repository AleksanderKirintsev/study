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

    ofstream vvod ( "tests\\00" );
    ofstream answer ( "tests\\00.a" );

    for ( int i = 0; i < N; i++ )
    {
        a[i] = 1 + rand() % 10;
        cout << a[i] << " ";
        vvod << a[i] << " ";
    }

    cout << endl << "otvet: ";
    cin >> otvet;
    answer << otvet;

    vvod.close();
    answer.close();

return 0;
}
