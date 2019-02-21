#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

#define NLIM 20

int n,k;

int main() {
    //srand(time(0));
    n = NLIM - rand() % (NLIM/2);
    k = n/2 - rand() % (n/4);

    cout << n << " " << k << endl;
    for(int i = 0; i < n; i++)
        cout << 1 + rand() % (NLIM/4) << " ";

    return 0;
}
