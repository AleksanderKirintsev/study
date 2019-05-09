#include <iostream>
using namespace std;

int n,m,k,*a,*w,*v,mid;

bool f(){
    int x = m + 3;
    while(){
        if((a[x-1] != 0 || a[x-1] < mid ) && a[x-1] != -1)
            x-= m+2;
        if(a[x-1] == 0 || a[x-1] > mid )
                x-=1;
        if(a[x+m+2] == 0 || a[x+m+2] > mid )
                x += m+2;
        if(a[x+m+2] == 0 || a[x+m+2] > mid )
                x += m+2;
    }

}

int main() {
    //freopen("tests/10","r",stdin);
    cin >> n >> m >> k;
    a = new int[(m+2)*(n+2)] {0};
    w = new int[k];
    for(int x, y, i = 0; i < k; i++) {
        cin >> x >> y;
        x++;y++;
        a[w[i] = x*(m+2)+y] = i+1;
    }

    for(int x = 0; x < n+2; x++)
        a[x*(m+2)] = a[x*(m+2)+m+1] = -1;
    for(int y = 0; y < m+2; y++)
        a[y] = a[(m+2)*(n+1)+y] = -1;

    int l = 1, int r = k;
    while (l <= r){
        mid = (l+r)/2;
        if (f) l = m;
        else r = m;
    }

    return 0;
}
//    for(int x = 0; x < n+2; x++) {
//        for(int y = 0; y < m+2; y++)
//            printf("%3d", a[x*(m+2)+y]);
//        cout << "\n";}
