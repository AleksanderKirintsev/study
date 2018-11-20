#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;       // char 16 бит, n = 1 000 000
    cin >> n >> s; //1 000 000

    for (int i = 0; i < n - 1; i++) //10 000 000
        if (s[i] != s[i + 1]) {
            cout << "Yes\n" << i+1 << " " << i + 2 << " " << 1;
            return 0;
        }
    cout << "No";
    return 0;
}
