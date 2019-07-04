#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n,h,v;
int **a;
deque<pair<int,int>> q;
int dx[6] ={-1, -1,  0, 1,  1,  0};
int dy[6] ={0 ,  1,  1, 1,  0, -1};

int void_processing(int x, int y){
    int sum = 0;
    q.push_back({x,y});

    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop_front();
        a[p.X][p.Y] = 1;
        sum++;

        for(int i = 0; i < 6; i++){
            x = p.X+dx[i];
            y = p.Y+dy[i]-(p.X%2 && dx[i]);
            if(a[x][y] == 0){
                a[x][y] = 1;
                q.push_back({x,y});
            }
        }
    }
    return sum;
}

int main(){
    //freopen("tests/00","r",stdin);
    cin >> n >> h >> v;
    a = new int*[h+2];
    for(int i = 0; i < h+2; i++){
        a[i] = new int[v+2];
        fill_n(a[i],v+2,1);
    }

    for(int i = 0; i < h+2; i++){
        for(int j = 0; j < h+2; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    for(int x = 1; x <= h; x++){
        for(int y = 1; y <= v; y++){
            char c;
            cin >> c;
            if(c =='.')
                a[x][y] = 0;
        }
    }

    int idx = 0;
    int *volumes = new int[h*v]{};
    for(int x = 1; x <= h; x++)
        for(int y = 1; y <= v; y++)
            if(a[x][y] == 0)
                volumes[idx++] = void_processing(x,y);

    sort(volumes,volumes+idx,greater<int>());

    int ans = 0;
    for(int i = 0; i < idx && n > 0; i++,ans++)
        n -= volumes[i];

    cout << ans;
    return 0;
}
