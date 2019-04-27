#include <iostream>
using namespace std;

int n,x0,y0,x1,y1,*v;
int moves[8][2]= {{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2}};

void wave() {
    for(int x = 2; x < n + 2; x++)
        for(int y = 2; y < n + 2; y++)
            if(v[x*(n+4)+y] == 1) {
                for(int i = 0; i < 8; i++) {
                    int x2 = x + moves[i][0];
                    int y2 = y + moves[i][1];
                    if (v[x2*(n+4)+y2] > 1)
                        v[x*(n+4)+y] = (v[x*(n+4)+y] == 1 ? v[x2*(n+4)+y2]+1 : min(v[x*(n+4)+y],v[x2*(n+4)+y2]+1));
                }
            }

}
int main() {
    //freopen("tests//00","r",stdin);
    cin >> n >> x0 >> y0 >> x1 >> y1;
    x0+= 2;
    y0+= 2;
    x1+= 2;
    y1+= 2;

    v = new int[(n+4)*(n+4)] {0};
    for(int x = 2; x < n+2; x++)
        for(int y = 2; y < n+2; y++)
            v[x*(n+4)+y] = 1;

    v[x0*(n+4)+y0] = 2;
    for(int i = 0; i < 8; i++) {
        int x2 = x0 + moves[i][0];
        int y2 = y0 + moves[i][1];
        if (v[x2*(n+4)+y2] == 1)
            v[x2*(n+4)+y2] = v[x0*(n+4)+y0]+1;
    }

    for(int x = 2; x < n + 2; x++)
        for(int y = 2; y < n + 2; y++)
            if(v[x*(n+4)+y] == 1)
                wave();

//    for(int x = 0; x < n + 4; x++){
//        for(int y = 0; y < n + 4; y++)
//            cout << v[x*(n+4)+y];
//        cout << endl;
//    }
            cout << v[x1*(n+4)+y1] - 2;
    return 0;
}
