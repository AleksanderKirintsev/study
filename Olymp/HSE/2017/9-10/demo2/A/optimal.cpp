#include <iostream>

using namespace std;

int main() {
    int h, m, s, lh, lm, ls, days = 1, n; // lh lm ls хранят предыдущее значение
    char c;

    cin >> n;
    cin >> lh >> c >> lm >> c >> ls;

    for ( int i = 1; i < n; i++ ) {
        cin >> h >> c >> m >> c >> s;

        if ( h < lh )
            days++;
        else if ( h == lh && m < lh )
            days++;
        else if ( h == lh && m == lh && s <= ls )
            days++;

        lh = h;
        lm = m;
        ls = s;

    }
    cout << days;
    return 0;
}
