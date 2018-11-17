#include <iostream>
using namespace std;

int main() {
    int n, m, s = 0, w = 1, q;
    char c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '.') {
                s += !w;
                else {
                    w = !w;
                    q++;
                }
            }


            cout << s + q / 2;
            return 0;
        }
