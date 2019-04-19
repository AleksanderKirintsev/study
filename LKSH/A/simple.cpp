#include <iostream>
using namespace std;

int n,P,q,x,*a= new int[500002];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cin >> n >> P;

    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }
    cin >> q;

    for(int i = 0; i < q; i++){
        char c;
        cin >> c >> x;
        if (c == '+'){
            a[x+1] += a[x];
            a[x] = 0;
            }
        if (c == '?')
            cout << a[x] <<'\n';
    }
    return 0;
}
