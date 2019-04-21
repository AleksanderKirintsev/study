#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,h,v,**p;
char **a;
vector<int> ms;

int f(int i,int j) {
    int q = 1;
    p[i][j] = 1;

    if (j+1 <= v-1 && a[i][j+1] == '.' && p[i][j+1] == 0)
        q += f(i,j+1);

    if (i+1 <= h-1 && a[i+1][j] == '.' && p[i+1][j] == 0)
        q += f(i+1,j);

    if (j-1 >= 0 && a[i][j-1] == '.' && p[i][j-1] == 0)
        q += f(i,j-1);

    if (i-1 >= 0 && a[i-1][j] == '.' && p[i-1][j] == 0)
        q += f(i-1,j);

    return q;
}

int main() {
    cin >> n >> h >> v;

    a = new char *[h];
    p = new int *[h];
    for (int i = 0; i < h; i++) {
        a[i] = new char[v];
        p[i] = new int[v];
    }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < v; j++) {
            cin >> a[i][j];
            p[i][j] = 0;
        }

    for(int i = 0; i < h; i++)
        for(int j = 0; j < v; j++)
            if (a[i][j] == '.' && p[i][j] == 0) {
                int d = f(i,j);
                ms.push_back(d);
            }

    sort(ms.rbegin(),ms.rend());
    for (int i = 0,j = 0; i < ms.size(); i++) {
        j++;
        n -= ms[i];
        if (n <= 0) {
            cout << j;
            break;
        }
    }

    return 0;
}
