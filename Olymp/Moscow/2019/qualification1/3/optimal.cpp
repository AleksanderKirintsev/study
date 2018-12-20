#include <iostream>
#include <vector>
using namespace std;

int main() {
    //freopen("tests/**","r",stdin);
    int n,w;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        a[i] = i+1;
    for (int k = 2; k <=n; k*=2) {
        for (int j = 0; j < n/k; j++) {
            cin >> w;
            if (w == 1)
                a[j * 2 + 1] = 0;
            else
                a[j * 2] = 0;

            /*        for(int i = 0; i < n / k; i++)
                        cout << a[i] << " ";
                    cout << endl;*/
        }
        int b[n/k],ind = 0;
        for(int i = 0; i < n; i++)
            if(a[i]!=0) {
                b[ind] = a[i];
                ind++;
            }
        for (int i = 0; i < n; i++)
            a[i] = 0;

        for ( int i = 0; i < n / k; i++)
            a[i] = b[i];

    }
    cout << a[0];
    return 0;
}


