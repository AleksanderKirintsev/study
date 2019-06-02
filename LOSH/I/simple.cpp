#include <iostream>
#include <algorithm>
using namespace std;

int n, h, v;
int *a;
int moves[6][2] = {{-1, 0},{-1, 1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}};
#define a(x,y) a[x*(v+2)+y]

int main() {
//    freopen("tests/05", "r", stdin);
    cin >> n >> h >> v;
    int lim = h * v;
    a = new int[(h+2)*(v+2)];
    for(int i = 0; i < (h+2)*(v+2); i++)
        a[i] = lim;

    for (int x = 1, i = 0; x < h + 1; x++) {
        char c;
        for(int y = 1; y < v + 1; y++) {
            cin >> c;
            if (c == '.')
                a(x,y) = i++;
        }
    }

    int s;
    do {
        s = 0;
        for (int x = 1; x < h + 1; x++)
            for (int y = 1; y < v + 1; y++)
                if (a(x, y) < lim) {
                    int mm = a(x, y);
                    for (int m = 0; m < 6; m++)
                        mm = min(a((x + moves[m][0]), (y + moves[m][1] - ((x % 2) && (m < 4)))), mm);
                    s += (a(x, y) > mm);
                    a(x, y) = mm;
                }
    } while (s > 0);

    int *q = new int[lim+1]{0};
    for (int x = 1; x < h + 1; x++)
        for (int y = 1; y < v + 1; y++)
            q[a(x,y)]++;

    sort(q, q+lim, greater<int>());

    int r;
    for (r = 0; n > 0; r++)
        n-=q[r];
    cout << r;

    return 0;
}
