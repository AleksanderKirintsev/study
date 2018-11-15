#include <iostream>
using namespace std;

int main() {
    int n, m, s = 0, l, q,g = 0;
    char c;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c =='.' && g == 1)
                s+=1;
            else
                g = !g;

        }
    }

    cout << s;
    return 0;
}
