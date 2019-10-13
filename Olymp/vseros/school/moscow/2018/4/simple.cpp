#include <iostream>
using namespace std;
int n, *a;
int main() {
// блок чтения данных
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

//блок заполнения вспомогательной структуры
    bool coupes[9];//1 - купе свободно, 0 - купе занято
    //тут будет код заполнения структуры, т.е. по оканчении его i-e купе полностью свободно, если coupes[i]==1
    int u[6] = {1,2,3,4,53,54},v[55]={};
    for(int i = 0; i < n; i++)
        v[a[i]] = 1;
    for(int i = 0; i < 9; i++){
        coupes[i] = 1;
        for(int j = 0; j < 6; j++)
            coupes[i]*=v[u[j]];
        for(int j = 0; j < 4; j++)
            u[j]+=4;
        u[4]-=2;
        u[5]-=2;
    }

//блок обработки вспомогательной структуры
    int mx = 0;
    for(int i = 0, tmp = 0; i < 9; i++)
            mx = max(tmp = (tmp+coupes[i])*coupes[i],mx);
    cout << mx;
    return 0;
}
