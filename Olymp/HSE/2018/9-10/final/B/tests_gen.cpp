#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
/*
 1. Сгенерировать условие случайным образом
 2. Вывести условие на экран
 3. Прочитать ответ
 4. Записать условие в файл без расширения, ответ в файл с расширением .а
 5. Перейти к пункту 1 если не создано достаточно тестов
*/

#define NLIM 10
#define AB 50
#define TLIM 7
#define X first
#define Y second
int main() {
    srand ( time ( NULL ) );
    int N;
    pair<int,int> A[10];
    pair<int,int> B[10];

    for ( int t = 3; t < TLIM; t++ ) {

        N = NLIM - rand() % ( NLIM / 2 );
        for ( int i = 0; i < N; i++ ) {
            A[i].X = 1 + rand() % AB;
            A[i].Y = 1 + A[i].X + rand() % (AB - A[i].X);
        }

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ));
        infile << N << endl;
        for ( int i = 0; i < N; i++ )
            infile << A[i].X << " " << A[i].Y << endl;
        infile.close();

        sort (A, A + N, [](const pair<int,int> &l, const pair<int,int> &r) {return l.X < r.X;});

        cout << N << endl;
        for ( int i = 0 ; i < N;i++)
            cout << A[i].X << " " << A[i].Y << endl;
        cout << endl;

        for ( int i = 0 ; i < N;i++)
            cin >> B[i].X >>  B[i].Y;
        cout << endl;

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        for ( int i = 0; i < N; i++ )
            afile << B[i].X << " " << B[i].Y << endl;
        afile.close();
   }


    return 0;
}
