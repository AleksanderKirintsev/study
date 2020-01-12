#include <iostream>
#include <string>
using namespace std;
string s;
int f(int l, int r) {
    int q = r-l;
    for(int w = 1; w  <= (r-l)/2; w++){
        int c = 1;
        for(int i = l,j = r-w; j < r && c; i++,j++)
            if(s[i] != s[j])
                c = 0;
        if(c)
            q = min(q,min(f(l+w,r),f(l,r-w)));
    }
    return q;
}
int main() {
    cin >> s;
    cout << f(0,s.size());
    return 0;
}
