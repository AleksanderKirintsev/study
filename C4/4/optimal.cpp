#include <iostream>

using namespace std;

int main()
{
   int n,ans = 0;
   double a, m = 1e6;
   cin >> n;
   for (int i = 0; i < n; i++){
    cin >> a;
    if (a > 1.0000000)
        {
        ans++;
        m = min(a, m);
   }
   }
   cout << ans <<  " " << m;
    return 0;
}
