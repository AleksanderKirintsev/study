#include <iostream>
using namespace std;
#define X first
#define Y second
int n;
pair<int,int> *p;

int main() {
    cin >> n;
    p = new pair<int,int>[n];
    for(int i = 0 ; i < n; i++)
        cin >> p[i].X >> p[i].Y;

    int *ans = new int[n],mn = 1e9;
    for(int i = 0; i  < (1<<n)-1; i++){
        int sum1 = 0, sum2 = 0;
        int *a = new int[n]{};
        for(int j = 0; j < n; j++){
            if((i&(1<<(n-j-1))) == 0){
                sum2+=p[(n-j-1)].Y;
                a[(n-j-1)] = 2;
            }
            else{
                sum1+=p[(n-j-1)].X;
                a[(n-j-1)] = 1;
            }
        }
        if(mn > max(sum1,sum2)){
            mn =max(sum1,sum2);
            delete ans;
            ans = a;
        }else
            delete a;
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}
