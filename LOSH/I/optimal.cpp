#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

#define P make_pair
#define X first
#define Y second

int n,h,v;
vector<vector<int>> a;
deque<pair<int,int>> q;
pair<int,int> moves[2][6]= {{P(-1,0),P(-1,1),P(0,1),P(1,1),P(1,0),P(0,-1)},{P(-1,-1),P(-1,0),P(0,1),P(1,0),P(1,-1),P(0,-1)}};

int V(){
    int sum = 0;
    pair<int,int> p;
    while(!q.empty()){
        p = q.front();
        q.pop_front();
        a[p.X][p.Y] = 1;
        sum++;

        for(int i = 0; i < 6; i++){
            int x = p.X+moves[p.X%2][i].X;
            int y = p.Y+moves[p.X%2][i].Y;
            if(a[x][y] == 0){
                a[x][y] = 1;
                q.push_back({x,y});
            }
        }
    }
    return sum;
}

int main(){
    //freopen("tests/14","r",stdin);
    cin >> n >> h >> v;
    a.resize(h+2,vector<int>(v+2,1));

    for(int x = 1; x <= h; x++)
        for(int y = 1; y <= v; y++){
            char c;
            cin >> c;
            if(c =='.')
                a[x][y] = 0;
        }

    vector<int> volumes;
    for(int x = 1; x <= h; x++)
        for(int y = 1; y <= v; y++)
            if(a[x][y] == 0){
                q.push_back({x,y});
                volumes.push_back(V());
            }

    int ans = 0;
    sort(volumes.rbegin(),volumes.rend());
    for(int i = 0; i < int(volumes.size()) && n > 0; i++,ans++)
        n -= volumes[i];

    cout << ans;
    return 0;
}
