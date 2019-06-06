#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    srand ( time ( NULL )* stoi(argv[2]));

    int q = 0;
    int h = stoi(argv[1]);
    int *a = new int[h*h];

    for(int i = 0; i < h*h; i++){
        a[i] = rand() % 2;
        q += a[i];
    }

    int n = q - rand() % (q/2);
    cout << n << " " << h << " " << h << '\n';
    for(int i = 0 ; i < h; i++){
        if (i%2)
            cout << ' ';
        for(int j = 0 ; j < h; j++)
            cout << (a[i*h+j] ? '.' : '#');
        cout << '\n';
    }

    return 0;
}
