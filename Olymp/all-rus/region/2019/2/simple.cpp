#include <iostream>
#include <cmath>
using namespace std;
long long ans = -1,k;

int main(){
    cin >> k;
    int n = (abs(k)+1)/2 + ((abs(k)+1)/2 % 2 != 0);
    for(int i = 0; i <= n;i++)
        if (i*i + k == sqrt(i*i + k )* sqrt(i*i + k )){
            ans = sqrt(i*i + k );
            break;
            }
    if(ans == -1)
        cout << "none";
    else
        cout << ans;
    return 0;
}
