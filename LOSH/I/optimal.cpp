#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n,h,v,*a,moves[2][6];

map<int,set<int>> mp;

void print() {
    for(int x = 0; x < h+2; x++) {
        for(int y = 0; y < v+2; y++)
            printf("%3d", a[x*(v+2)+y]);
        printf("\n");
    }
    printf("\n");
}

inline void process_adjacent(int x0) {
    int am = mp.size()+1;
    for(int i = 0; i < 6; i++){
        int x = ((x0 / (v+2)) % 2 == 0 ? x0 + moves[0][i] : x0 + moves[1][i]);
        if (a[x] > 0)
            am = min(am, a[x]);
            }

    mp[am].insert(x0);
    a[x0] = am;

    for(int i = 0; i < 6; i++) {
        int x = (x0 / (v+2) % 2 ? x0 + moves[0][i] : x0 + moves[1][i]), y = a[x];
        if (y > am){
            mp[am].insert(mp[y].begin(), mp[y].end());
            for(auto it:mp[y])
                a[it] = am;
            mp[y].clear();
        }
    }
}

int main(){
    //freopen("tests/01","r",stdin);
    cin >> n >> h >> v;
    a = new int[(h+2)*(v+2)]{};
    moves[0][0] = -v-2; moves[0][1] = -v-1; moves[0][2] = 1; moves[0][3] = v+3; moves[0][4] = v+2; moves[0][5] = -1;
    moves[1][0] = -v-3; moves[1][1] = -v-2; moves[1][2] = 1; moves[1][3] = v+2; moves[1][4] = v+1; moves[1][5] = -1;
    //{{ -v-2, -v-1, 1, v+3, v+2, -1 }, { -v-3, -v-2, 1, v+2, v+1, -1 }};

    for(int x = 1;x < h + 1; x++)
        for(int y = 1;y < v + 1; y++){
            char c;
            cin >> c;
            if(c == '#')
                a[x*(v+2)+y] = -1;
        }

    for(int x = 0; x < h+2; x++)
        a[x*(v+2)] = a[x*(v+2)+v+1] = -1;
    for(int y = 0; y < v+2; y++)
        a[y] = a[(v+2)*(h+1)+y] = -1;

    for(int x = 1;x < h + 2; x++)
        for(int y = 1;y < v + 2; y++)
            if(a[x*(v+2)+y] == 0)
                process_adjacent(x*(v+2)+y);

    vector<int> ss;
    for(int i = 1; i < mp.size(); i++)
        ss.push_back(mp[i].size());
    sort(ss.rbegin(),ss.rend());

    int ans = 0;
    for(int i = 0; i < ss.size() && n > 0; i++,ans++)
        n -=ss[i];

    cout << ans;
    return 0;
}
