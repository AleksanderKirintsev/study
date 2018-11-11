#include <iostream>
using namespace std;

int main() {
    int n, m, s = 0, l, q;
    char c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        l = q = 0;
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c != '.' && q == 1) {
                s += j - l;
                q = 0;

            } else if (c != '.' && q == 0) {
                l = j;
                q++;
            }
        }
    }

    cout << s;
    return 0;
}
