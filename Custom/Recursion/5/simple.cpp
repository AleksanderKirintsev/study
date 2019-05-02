#include <iostream>
using namespace std;

int m,n,k,*s;

int main(){
    freopen("tests/10","r",stdin);
    cin >> m >> n >> k;
    s = new int[m*n]{0};
    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        s[x*n+y] = i+1;
    }

    return 0;
}
