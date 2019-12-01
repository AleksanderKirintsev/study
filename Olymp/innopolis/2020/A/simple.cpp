#include <iostream>
#include <algorithm>
using namespace std;
int a,b,x;
int main() {
    cin >> a >> b >> x;
    int ans = 0;
    for(int i = 1; i*a <=1000; i++)
        for(int j = 1; i * a + j * b <=1000; j++)
            if((i*a*100)%(i*a+j*b) == 0 && (i*a*100)/(i*a+j*b) == x)
                ans = max(ans,i*a+j*b);
    cout << ans;
    return 0;
}
