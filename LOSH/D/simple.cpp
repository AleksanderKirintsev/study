#include <iostream>
#include <map>
#include <string>
using namespace std;

string s,a;
int n;

int get_num (string d,int &i) {
    string num;
    for(; '9' >= d[i] && d[i] >= '0'; i++)
        num += d[i];
    return (num.empty() ? 1 : stoi(num));
}

int main() {
    cin >> s >> n >> a;

    map<char,int> m,m1;

    for(int i = 0; i < a.size(); i++) {
        int j = i + 1;
        m[a[i]] += get_num(a,j);
        m1[a[i]] = 0;
        i = j-1;
    }

//      for(auto it = m.begin(); it != m.end(); it++)
//        cout << it->first << " = " << it->second << endl;

    for(int i = 0; i < s.size(); i++) {
        int j = i+1;
        m1[s[i]] += get_num(s,j) * n;
        i = j-1;
    }

//    for(auto it = m1.begin(); it != m1.end(); it++)
//         cout << it->first << " = " << it->second << endl;

    int mi = 2e9;
    for(auto it = m.begin(); it != m.end(); it++) {
        mi = min(m1[it->first] / m[it->first],mi);
    }
    cout << mi;

    return 0;
}
//D102AF801D
//ABCD 10
