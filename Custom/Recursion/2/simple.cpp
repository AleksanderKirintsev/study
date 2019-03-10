#include <iostream>

using namespace std;
int n;
int stairs(int a,int plevel){
  if (a == 0)
    return 1;

  int ans = 0;
  for (int level = 1; level < plevel; ++level) {
    if ((a - level) < 0)
      break;
    ans += stairs(a-level,level);
  }
  return ans;
}
int main() {

    cin >> n;
    cout << stairs(n,n+1);
    return 0;
}
