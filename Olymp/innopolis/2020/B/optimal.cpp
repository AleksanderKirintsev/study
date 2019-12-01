#include <iostream>
#include <cmath>
using namespace std;
int n;
string *s;
int main() {
    cin >> n;
    s = new string[n];
    int max_size = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        max_size = max(max_size,int(s[i].size()));
    }

    int ans = 0;
    for(int i = 0; i < max_size; i++){
        int a[26] = {};
        for(int j = 0; j < n; j++)
            if(i < s[j].size())
                a[s[j][i]-'a']++;
        int mx = 0, sum = 0;
        for(int d = 0; d < 26; d++){
            mx = max(a[d],mx);
            sum+=a[d];
        }
        ans+=(sum-mx);
    }
    cout << ans;
    return 0;
}
