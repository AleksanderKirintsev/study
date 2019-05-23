#include <iostream>
using namespace std;

int m,n,k,*a,*w;
int *moves;

void print() {
    for(int x = 0; x < n+2; x++) {
        for(int y = 0; y < m+2; y++)
            printf("%3d", a[x*(m+2)+y]);
        cout << "\n";
    }
    cout << "\n";
}

bool is_connected(int x,int y,int mw) {
    int z = x,d = 1;
    if(a[x] <= mw) {
        do {
            if(a[z+moves[d]] > mw)
                d = (d+1)% 4;
            else {
                z += moves[d];
                d = (d+3) % 4;
            }
        } while((z != x || d != 1) && z != y);
    }
    return z == y;
}

int main() {
//    freopen("tests/10","r",stdin);
    cin >> n >> m >> k;
    a = new int[(m+2)*(n+2)] {0};
    w = new int[k];
    moves = new int[4] {-m-2,1,m+2,-1};

    for(int x, y, i = 0; i < k; i++) {
        cin >> x >> y;
        a[w[i] = x*(m+2)+y] = k-i;
    }

    for(int x = 0; x < n+2; x++)
        a[x*(m+2)] = a[x*(m+2)+m+1] = k + 1;
    for(int y = 0; y < m+2; y++)
        a[y] = a[(m+2)*(n+1)+y] = k + 1;


    //print();
    int x = m+3, y = (n+1)*(m+2)-2;
    int l = 0, r = k;
    if (!is_connected(x,y,0)) {
        while(l+1 < r) {
            int mw = (l+r)/2;
            if(is_connected(x,y,mw))
                r = mw;
            else
                l = mw;
        }
    } else
        l = k;

    cout << k - l;
    return 0;
}
