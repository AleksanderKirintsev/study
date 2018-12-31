#include <iostream>
using namespace std;

int n,a[1000000],b[1000000];

int num(int l,int k) {
    int i,j;
    for (i = a[l],j = 1; j < k; j++)
        i = a[i-1];
    return i;
}

int main() {
    int n,k = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = a[0]; i != b[0] && k <= n+1; k++)
        i = a[i-1];

    if(k == n + 2) {
        cout << "No";
        return 0;
    }

    for ( int i = 1; i < n; i++)
        if (num(i,k) != b[i]) {
            cout << "No";
            return 0;
        }

    cout << "Yes";
    return 0;
}
