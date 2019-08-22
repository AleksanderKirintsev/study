#include <iostream>
using namespace std;

string s;
long long *a,ans = 0,v[34000][10],c;
bool check1(long long l, long long r,long long a){
    return(l <= a && a <= r);
}
bool check2(long long l, long long r,long long l1, long long r1,long long a){
    return((l <= a && a <= r) || (l1 <= a && a <= r1));
}
int main() {
    cin >> s;
    a = new long long[s.size()];
    for(long long i = 0; i < s.size(); i++){
        a[i] = s[i]-'0';
    }
    for(long long d = 0; d <= 9; d++){
        for(long long i = 0, j = 0; i < s.size(); i+=3,j++){
            int curr = 0;
            if(check1(100,122,a[i]*100+a[i+1]*10+a[i+2])){
                   v[j][d] = 1;
                continue;
            }

            if(a[i] == d && check2(65,90,97,99,a[i+1]*10+a[i+2])){
                v[j][d]++;
                }
            if(a[i+1] != a[i] && a[i+1] == d && check2(65,90,97,99,a[i]*10+a[i+2])){
                v[j][d]++;
                }
            if(a[i+2]!= a[i+1] && a[i+2] == d && check2(65,90,97,99,a[i]*10+a[i+1]))
                v[j][d]++;

        }
    }
    for(int d = 0; d <= 9; d++){
        long long curr = 1;
        for(int i = 0; i < s.size()/3; i++){
            curr*=v[i][d];
        }
        ans+=curr;
    }
    cout << ans;
    return 0;
}
