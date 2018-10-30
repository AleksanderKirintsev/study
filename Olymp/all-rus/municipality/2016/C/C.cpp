#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, p1, p2;
    double s2, s1, ans = 0;
    string s;
    cin >> n >> p1 >> p2 >> s1 >> s2;

    p1 *= 60;
    s1 /= 60;

    for (int i = 0; i < n; i++) {
        string d2, d1; // используются только для их ввода
        cin >> d1 >> d2 >> s;

        if (s == "SMS")
            p2--;
        else
            p1 -= ( (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0'));

    }
    ans += (p1 < 0 ? abs (p1) * s1 : 0);
    ans += (p2 < 0 ? abs (p2) * s2 : 0);

   printf("%0.2f",ans);
    return 0;

}
