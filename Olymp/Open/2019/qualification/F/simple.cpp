#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    vector<int> b(n),s(n),s1(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = i+1;
        s1[i] = i+1;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 1; i <= 10000000; i++) {
        for (int j = 0; j < n; j++) {
            s1[j] = s[a[j]-1];
        }
        if (s1 == b) {
            cout << "Yes";
            return 0;
        }
        s = s1;
    }

    cout << "No";
    return 0;
}
