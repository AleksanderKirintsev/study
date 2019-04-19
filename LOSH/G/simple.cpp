#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,n = 2;
    bool b;
    cin >> a;

    while (a>0) {
        b =true;
        while (n <= round(sqrt(a))) {
            if (a % n ==0) {
                cout << n << " ";
                a = a/n;
                b = false;
                break;
            }
            n++;
        }
        if (b) {
            cout << a;
            break;
        }
    }


    return 0;
}
