#include <iostream>
using namespace std;

int m,n,k,*a,*w;
int moves[4][2] {{-1,0},{0,1},{1,0},{0,-1}};

bool f(int x,int y) {
    if (a[x*(m+2) + y] != 0)
        return 0;
    if (x*(m+2) + y == n*(m+2)+m)
        return 1;

    a[x*(m+2) + y] = -1;
    int q = 0;
    for(int i = 0; i < 4; i++)
        q += f(x+moves[i][0],y+moves[i][1]);
    a[x*(m+2) + y] = 0;
    return q;
}

int main() {
    freopen("tests/00","r",stdin);
    cin >> n >> m >> k;
    a = new int[(m+2)*(n+2)] {0};
    w = new int[k];
    for(int x, y, i = 0; i < k; i++) {
        cin >> x >> y;

        a[w[i] = x*(m+2)+y] = i+1;
    }

    for(int x = 0; x < n+2; x++)
        a[x*(m+2)] = a[x*(m+2)+m+1] = k + 1;
    for(int y = 0; y < m+2; y++)
        a[y] = a[(m+2)*(n+1)+y] = k + 1;

    int ans = k;
    for (int i = k-1; i >= 0; i--) {
        a[w[i]] = 0;
        if (f(1,1))
            break;
        ans--;
    }
//    for(int x = 0; x < n+2; x++) {
//        for(int y = 0; y < m+2; y++)
//            printf("%3d", a[x*(m+2)+y]);
//        cout << "\n";}
    cout << ans;
    return 0;
}
