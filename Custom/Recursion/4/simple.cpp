#include <iostream>
using namespace std;

int n,x0,y0,x1,y1,*v;
int moves[8][2]={{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};
// Возвращает минимальное количевсто ходов за которое можно попасть из (x,y) в (x1,y1)
int f(int x,int y){
    if(x == x1 && y == y1)
        return 0;

    v[x*(n+4)+y] = 0;

    int m = n * n;
    for(int i = 0; i < 8; i++){
        int x2 = x+moves[i][0];
        int y2 = y+moves[i][1];
        if (v[x2*(n+4) + y2] == 1)
            m = min(m,f(x2,y2));
    }
    v[x*(n+4)+y] = 1;
    return m+1;
}

int main() {
    //freopen("tests//00","r",stdin);
    cin >> n >> x0 >> y0 >> x1 >> y1;
    x0 += 2;
    y0 += 2;
    x1 += 2;
    y1 += 2;

    v = new int[(n+4)*(n+4)] {0};
    for (int i = 2; i < n + 2; i++)
        for (int j = 2; j < n + 2; j++)
            v[i*(n+4)+j] = 1;

    cout << f(x0,y0);
    return 0;
}
