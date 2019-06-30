#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define Y first
#define X second

int n,h,v;
int a[1010][1010];
deque<pair<int,int>> q;
int dx[6] ={0 ,  1,  1, 1,  0, -1};
int dy[6] ={-1, -1,  0, 1,  1,  0};

int void_processing(int y, int x){
    int sum = 0;
    q.push_back({y,x});

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop_front();
        a[p.Y][p.X] = 1;
        sum++;

        for(int i = 0; i < 6; i++){
            y = p.Y+dy[i];
            x = p.X+dx[i]-(p.Y%2 && dy[i]);
            if(a[y][x] == 0){
                a[y][x] = 1;
                q.push_back({y,x});
            }
        }
    }
    return sum;
}

int main(){
    //freopen("tests/14","r",stdin);
    cin >> n >> h >> v;

    fill_n(a[0],v+2,1);
    fill_n(a[h+1],v+2,1);
    for(int y = 1; y <= h; y++){
        fill_n(a[y],v+2,1);
        for(int x = 1; x <= v; x++){
            char c;
            cin >> c;
            if(c =='.')
                a[y][x] = 0;
        }
    }

    int idx = 0;
    int *volumes = new int[h*v]{};
    for(int y = 1; y <= h; y++)
        for(int x = 1; x <= v; x++)
            if(a[y][x] == 0)
                volumes[idx++] = void_processing(y,x);

    sort(volumes,volumes+idx,greater<int>());

    int ans = 0;
    for(int i = 0; i < idx && n > 0; i++,ans++)
        n -= volumes[i];

    cout << ans;
    return 0;
}
