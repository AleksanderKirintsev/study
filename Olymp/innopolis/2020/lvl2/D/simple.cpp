#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int b, k;
int main() {
    string s;
    cin >> b >> k >> s;
    ll a = 0;
    for(int i = 0; i < s.size(); i++)
        a+=('a' <= s[i] && s[i] <= 'f' ? (s[i] - 'a')+10 : s[i] - '0') * pow(16,s.size()-i-1);
    for(int i = (1<<(b-1)); i < (1<<b) && k > 0; i++)
        if(a%i == 0){
            cout << hex << i << "\n";
            k--;
        }
    return 0;
}
