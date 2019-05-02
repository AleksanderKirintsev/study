#include <iostream>
using namespace std;

int m,n,k,*s;

int main(){
    cin >> m >> n >> k;
    s = new int[m*n]{0};
    for(int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        s[a*n+b] = i+2;
    }
    int l = 0,r = k;

    return 0;
}
