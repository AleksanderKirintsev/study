#include <iostream>

using namespace std;

void f(int n,char A,char B, char C) {
    if(n > 0) {
        f(n-1,A,C,B);
        cout << A << " -> " << B << " ";
        f(n-1,C,B,A);
    }
}
int main() {
    int q;
    cin >> q;
    f(q,'A','B','C');

    return 0;
}
