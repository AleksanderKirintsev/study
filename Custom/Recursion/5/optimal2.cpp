#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int m,n,k,idx = -1,*a,*w;
int *moves;
map<int,set<int>> mp;

void print() {
    for(int x = 0; x < n+2; x++) {
        for(int y = 0; y < m+2; y++)
            printf("%3d", a[x*(m+2)+y]);
        cout << "\n";
    }
    cout << "\n";
}

void process_adjacent(int x0) {
    int am = -mp.size()-1;
    for(int i = 0; i < 4; i++)
        if (a[x0+moves[i]] < 0)
            am = max(am, a[x0+moves[i]]);

    mp[am].insert(x0);
    a[x0] = am;

    for(int i = 0, x = x0 + moves[i]; i < 4; x = x0 + moves[++i])
        if (a[x] < am){
            mp[am].insert(mp[a[x]].begin(), mp[a[x]].end());
            int del = a[x];
            for(auto it:mp[a[x]])
                a[it] = am;
            mp[del].clear();
        }

}

int main() {
    //freopen("tests/10","r",stdin);
    cin >> n >> m >> k;
    a = new int[(m+2)*(n+2)] {0};
    w = new int[k];
    moves = new int[4] {-m-2,1,-1,m+2};

    for(int x, y, i = 0; i < k; i++) {
        cin >> x >> y;
        a[w[i] = x*(m+2)+y] = i+1;
    }

    for(int x = 0; x < n+2; x++)
        a[x*(m+2)] = a[x*(m+2)+m+1] = k + 1;
    for(int y = 0; y < m+2; y++)
        a[y] = a[(m+2)*(n+1)+y] = k + 1;

    //print();

    int s = a[m+3],f = a[(n+1)*(m+2)-2];
    int ans = min(s,f) ? min(s,f)-1 : (max(s,f) ? max(s,f)-1 : k);
    for(int i = k; i > ans && ans != k; i--)
        a[w[i-1]] = 0;

    //print();

    for(int x = 1; x < n+2; x++)
        for(int y = 1; y < m+2; y++)
            if (a[x*(m+2)+y] == 0)
                process_adjacent(x*(m+2)+y);


    for(; ans > 1 && a[(n+1)*(m+2)-2] != -1; ans--) {
        //print();
        a[w[ans-1]] = 0;
        process_adjacent(w[ans-1]);

    }

    cout << (ans == k ? 0 : ans + 1);

    return 0;
}
