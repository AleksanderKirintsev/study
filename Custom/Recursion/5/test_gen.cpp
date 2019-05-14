#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    int n = stoi(argv[1]),k = n * n * stoi(argv[2]) / 100;

    int *a = new int[n*n] {0};
    pair<int,int> *b = new pair<int,int>[k];
    srand ( time ( NULL )* stoi(argv[3]));
    for(int i = 0; i < k; i++){
        int j = rand() % (n*n);
        while(a[j] != 0)
            j = (j+1) % (n*n);
        a[j] = i+1;
        b[i] = {j / n + 1,j % n + 1};
    }

//    char* buffer = new char[3];
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < n; j++){
//            sprintf(buffer,"%3d",a[i*n+j]);
//            cout << buffer;
//            }
//        cout << "\n";
//    }

    cout << n << " " << n << " " << k << "\n";
    for(int i = 0; i < k; i++)
        cout << b[i].first << " " << b[i].second << "\n";

    return 0;
}
