#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    srand(time(0)*atoi(argv[3]));
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    cout << n << " " << k << endl;
    for(int i = 0; i < n; i++)
        cout << 1+rand()%(n/2)<< " ";

    return 0;
}
