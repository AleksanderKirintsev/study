#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string s,s1,s2;

int main() {
    //freopen("tests/10","r",stdin);

    for(int i = 0; i < 7000; i++) {
        string c,c1,c2;
        bool f = 0,f1=0,f2=0,abc = 0;

        cin >> s >> s1 >> s2;

        for(int j = 0; j < max(max(s.size(),s1.size()),max(s1.size(),s2.size())); j++) {
            f = (s[j] == '.' ? 1 : f);
            f1 = (s1[j] == '.' ? 1 : f1);
            f2 = (s2[j] == '.' ? 1 : f2);

            if( s[j] >= 'A' && 'Z' >= s[j] || s1[j] >= 'A' && 'Z' >= s1[j] || s2[j] >= 'A' && 'Z' >= s2[j])
                abc = 1;
            if (f == 0 && c.size() < s.size())
                c += s[j];
            if (f1 == 0 && c1.size() < s1.size())
                c1 += s1[j];
            if (f2 == 0 && c2.size() < s2.size())
                c2 += s2[j];

        }

        if(abc == 0) {
            long long x = stoll(c);
            long long y = stoll(c1);
            long long z = stoll(c2);

            if(x < y && x < z)
                cout << s << endl;
            if(y < x && y < z)
                cout << s1 << endl;
            if(z < x && z < y)
                cout << s2 << endl;
        } else {
            if(s < s1 && s < s2)
                cout << s << endl;
            if(s1 < s && s1 < s2)
                cout << s1 << endl;
            if(s2 < s && s2 < s1)
                cout << s2 << endl;
        }
    }


    return 0;
}
