#include <iostream>
#include <string>
using namespace std;

string a,b,c;
bool F(string v, string u) {
    for(int i = 0; i <= int(u.size()) - int(v.size()); i++){
        string x = u.substr(i,v.size());
        if(v == x)
            return 1;
    }
    return 0;
}

int main() {
    cin >> a >> b >> c;
    string ans;
    for(int i = 0; i < a.size(); i++)
        for(int j = i; j < a.size(); j++) {
            string tmp = a.substr(i,j-i+1);
            ans = (tmp.size() > ans.size() && F(tmp,b) && F(tmp,c) ? tmp : ans);
        }
    cout << ans;
    return 0;
}
