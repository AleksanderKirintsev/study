#include <iostream>
using namespace std;

int main() {
    string s;
    int sum = 0;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        sum += (s[i] == '2' ? 2 : -3);

    cout << sum;
    return 0;

}
