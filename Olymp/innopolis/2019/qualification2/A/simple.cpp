#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //freopen("tests/00","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);


    int x,y,x1 = 0,y1 = 0;
    cin >> x >> y;

    if (x > y) {
        if(y > 0) {
            for (y1 = 1; y1 < y; y1++)
                cout << x1 << ":" << y1 << endl;
            for (x1 = 0; x1 <= x; x1++)
                cout << x1 << ":" << y1 << endl;
        } else
            for (x1 = 1; x1 <= x; x1++)
                cout << x1 << ":" << y1 << endl;
    } else {
        if(x > 0) {
            for (x1 = 1; x1 < x; x1++)
                cout << x1 << ":" << y1 << endl;
            for (y1 = 0; y1 <= y; y1++)
                cout << x1 << ":" << y1 << endl;
        } else
            for (y1 = 1; y1 <= y; y1++)
                cout << x1 << ":" << y1 << endl;
    }
return 0;
}
