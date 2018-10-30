#include <iostream>
using namespace std;

int nod (int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return (a == 0 ? b : a);
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x = abs (x1 - x2);
    int y = abs (y1 - y2);

    cout << x + y - nod (x, y);
    return 0;
}
