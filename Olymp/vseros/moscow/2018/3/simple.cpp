#include <iostream>
using namespace std;
int h,m,s;
int main() {
    int ts[3] = {};
    for(int i = 0; i < 3 ; i++){
        scanf("%d:%d:%d",&h,&m,&s);
        ts[i] = h*3600+m*60+s;
    }

    ts[2]+=(ts[0] > ts[2] ? 86400 : 0);
    ts[1] += (ts[2] - ts[0])/2;
    ts[1]%=86400;

    printf("%02d:%02d:%02d",ts[1]/3600,ts[1]%3600/60,ts[1]%3600%60);
    return 0;
}
