#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
/*
 1. Сгенерировать условие случайным образом
 2. Вывести условие на экран
 3. Прочитать ответ
 4. Записать условие в файл без расширения, ответ в файл с расширением .а
 5. Перейти к пункту 1 если не создано достаточно тестов
*/

#define NLIM 10
#define MLIM 10
#define TLIM 7
int main()
{
    int N,an,a[NLIM],a1[NLIM];
    string ans,s,s1;

    srand ( time ( NULL ) );

    for ( int t = 2; t < TLIM; t++ )
    {
        N =1 + rand() % NLIM;

        for ( int i = 0; i < N; i++ ){
            a[i] = rand() % NLIM ;
            a1[i] = rand() % NLIM ;
        }
        cout << N << endl;
        for ( int i = 0; i < N; i++ )
            cout << a[i] << "." << a1[i] << endl;
        cout << endl;

        cin >> an >> ans;
        cout << endl;
        ofstream infile ( "tests\\0" + to_string ( t ) );
        infile << N << endl;
        for ( int i = 0; i < N; i++ )
            infile << a[i] << "." << a1[i] << endl;
        infile.close();

        ofstream afile ( "tests\\0" + to_string ( t ) + ".a" );
        afile << an << " " << ans;
        afile.close();
    }


    return 0;
}
