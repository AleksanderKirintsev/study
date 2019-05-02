#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define NLIM 10
int main(int argc, char* argv[]) {
    srand ( time ( NULL ) );
//    cin.tie(0);
//    cin.sync_with_stdio(0);
//    cout.tie(0);
    int n = 10, k = 70;
    //int n = stoi(argv[1]),k = n * n * stoi(argv[2]) / 100;
    cout << n << " " << n << " " << k << "\n";

    int *a = new int[n*n] {0};
    for(int i = 0; i < k; i++){
        int j = ((rand() %  n) * n) % (n*n);
        while(a[j] != 0)
            j = (j+1) % (n*n);
        a[j] = i+1;
//        cout << j / n << " " <<j % n << "\n";
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%3d", a[i*n+j]);
        cout << "\n";
    }

    return 0;
}
