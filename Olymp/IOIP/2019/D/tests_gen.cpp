#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc,char **argv){
    srand(time(0)*atoi(argv[3]));
    int n = 1,m = atoi(argv[1]),p = atoi(argv[2]);
    cout << n << " " << m << " " << p << "\n";
    int ps[m+1]={};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a = rand()%10;
            printf("%2d ",a);
            ps[j+1] = ps[j]+a;
        }
        cout << "\n";
    }
    for(int i = 1; i<= m; i++)
        printf("%2d ",ps[i]);

    return 0;
}
