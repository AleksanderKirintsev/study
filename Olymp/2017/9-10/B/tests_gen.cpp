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

#define NLIM 5
#define AB 10
#define TLIM 7
int main() {
    int N, A[AB], B[AB], Aa[AB], Ba[AB];

    srand ( time ( NULL ) );

    for ( int t = 2; t < TLIM; t++ ) {
        N = NLIM - rand() % ( NLIM / 2 );
        for ( int i = 0; i < N; i++ ) {
            A[i] = 1 + rand() % AB;
            B[i] = 1 + rand() % AB;
            if (A[i] > B[i]){
                int tmp = A[i];
                A[i]= B[i];
                B[i]=tmp;
            }

        }

        cout << N << endl;
        for ( int i = 0; i < N; i++ )
            cout << A[i] << " " << B[i] << endl;
        cout << endl;
        for ( int i = 0; i < N; i++ )
            cin >> Aa[i] >> Ba[i];

        ofstream infile ( "tests\\" + to_string ( t % 10 ) + to_string ( t ) );
        infile << N << endl;
        for ( int i = 0; i < N; i++ )
            infile << A[i] << " " << B[i] << endl;
        infile.close();

        ofstream afile ( "tests\\0" + to_string ( t % 10 ) + to_string ( t ) + ".a" );
        for ( int i = 0; i < N; i++ )
            afile << Aa[i] << " " << Ba[i] << endl;
        afile.close();
    }


    return 0;
}
