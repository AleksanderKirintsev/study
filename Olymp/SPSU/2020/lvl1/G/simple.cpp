#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int f(string x) {
    int q = 0,ans = x.size();
    string pr,su,tmp;
    tmp = x;
    reverse(tmp.begin(),tmp.end());
    for(int i = 0; i < x.size()/2; i++) {
        pr+=x[i];
        su+=tmp[i];
        reverse(su.begin(),su.end());
        if(pr == su) {
            string s1,s2;
            for(int i = pr.size(); i < x.size(); i++)
                s1+=x[i];
            for(int i = 0; i < x.size()-su.size(); i++)
                s2+=x[i];
            ans = min(ans,min(f(s1),f(s2)));
        }
        reverse(su.begin(),su.end());
    }
    return ans;
}
int main() {
    cin >> s;
    cout << f(s);
    return 0;
}
