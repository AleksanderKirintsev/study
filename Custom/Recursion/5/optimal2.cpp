#include <iostream>
#include <set>
#include <map>
using namespace std;

int m,n,k,*a,*w;
int *moves;
map<int,set<int>> mp;

int wave(int i) {
    int q = 0;
    for(int x = 1; x < n + 2; x++)
        for(int y = 1; y < m + 2; y++)
            if(a[x*(n+4)+y] == 0) {
                set<int> tmp;
                for(int j = 0; j < 4; j++) {
                    int x1 = x*(n+4)+y+moves[i];
                    if (a[x1] == i) {
                        tmp.insert(x1);
                        a[x*(n+4)+y] = i;
                        q++;
                        break;
                    }
                }
                mp[i] = tmp;
            }
    return q;
}
int main() {
    //freopen("tests/10","r",stdin);
    cin >> n >> m >> k;
    a = new int[(m+2)*(n+2)] {0};
    w = new int[k];
    moves = new int[4] {-m-2,1,-1,m+2};

    for(int x, y, i = 0; i < k; i++) {
        cin >> x >> y;
        a[w[i] = x*(m+2)+y] = i+1;
    }

    for(int x = 0; x < n+2; x++)
        a[x*(m+2)] = a[x*(m+2)+m+1] = k + 1;
    for(int y = 0; y < m+2; y++)
        a[y] = a[(m+2)*(n+1)+y] = k + 1;



    return 0;
}
