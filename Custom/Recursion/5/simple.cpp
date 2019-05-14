#include <iostream>
using namespace std;

int m,n,k,*a,*w,ans;
int *moves;

void print(){
    for(int x = 0; x < n+2; x++) {
        for(int y = 0; y < m+2; y++)
            printf("%3d", a[x*(m+2)+y]);
        cout << "\n";
    }
    cout << "\n";
}

bool f(int x) {
    if (a[x] != 0 || a[(n+1)*(m+2)- 2])
        return 0;
    if (x == n*(m+2)+m)
        return 1;

    a[x] = -1;
    int q = 0;
    for(int i = 0; i < 4; i++){
        //print();
        if (q = f(x+moves[i])){
            break;
        }
    }
    a[x] = 0;
    return q;
}

int main() {
    //freopen("tests/12","r",stdin);
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


    //print();
    ans = k;
    if (!f(m+3)) {
        do {
            ans--;
            a[w[ans]] = 0;
        } while(!f(m+3));
        ans++;
    } else
        ans = 0;

    cout << ans;
    return 0;
}
