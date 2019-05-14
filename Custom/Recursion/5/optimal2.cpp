#include <iostream>
#include <set>
#include <map>
using namespace std;

int m,n,k,*a,*w;
int *moves;
map<int,set<int>> mp;

void print(){
    for(int x = 0; x < n+2; x++) {
        for(int y = 0; y < m+2; y++)
            printf("%3d", a[x*(m+2)+y]);
        cout << "\n";
    }
    cout << "\n";
}

int wave() {
    int q = 0,f = 0;
    for(int x = 1; x < n + 2; x++)
        for(int y = 1; y < m + 2; y++)
            if(a[x*(n+2)+y] == -1) {
                int tmp = 0;
                for(int j = 0; j < 4; j++) {
                    int x1 = x*(n+2)+y+moves[j];
                    tmp+=(a[x1] == k+1);
                    if (a[x1] == 0 ) {
                        a[x1] = -1;
                        tmp++;
                    }
                }
                if(tmp == 4)
                    a[x*(n+2)+y] = -2;
                q++;
            }
        return (a[(n+1)*(m+2)-2] < 0);
}

int main() {
    //freopen("tests/00","r",stdin);
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

    a[m+3] = (a[m+3] ? a[m+3] : -1);

    int ans = k;
    if (a[n*(m+2)+m+1]>=0) {
        do {
            ans--;
            a[w[ans]] = {w[ans] == m + 3 ? -1 : 0};
           // print();
        } while(!wave());
        ans++;
    } else
        ans = 0;

    cout << ans;


    return 0;
}
