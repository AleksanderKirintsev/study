#include <iostream>

using namespace std;

void f(int i) {
    if (i > 0) {
        int n;
        cin >> n;
        f(i-1);
        cout << n << " ";
    }
}
int main() {
    int q;
    cin >> q;
    f(q);

    return 0;
}
