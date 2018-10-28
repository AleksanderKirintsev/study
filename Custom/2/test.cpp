#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define NLIM 25000

int main() {
    srand(time(0));
    int n = NLIM ;
    int a[NLIM],b[NLIM];

    for (int i = 0; i < n; i++){
        a[i] = rand() % 1001;
        b[i] = a[i];
    }

    sort(a,a+n);
    cout << "done!\n";

    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) {
            if (b[j + 1] < b[j])
                swap (b[j], b[j + 1]);
        }
    cout << "done!\n";
    return 0;
}
