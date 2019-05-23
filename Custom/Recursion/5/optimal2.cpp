#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int m,n,k,idx = -1,*a,*w;
int *moves;
map<char,set<int> > mp;

void print() {
    for(int x = 0; x < n+2; x++) {
        for(int y = 0; y < m+2; y++)
            printf("%3d", a[x*(m+2)+y]);
        cout << "\n";
    }
    cout << "\n";
}
void add(set<int> &s1, set<int> &s2,int i) {
    for(auto x : s2) {
        s1.insert(x);
        a[x] = i;
    }
    s2.clear();

}
void check_point(int x1) {
    set<int> sets;
    for(int i = 0; i < 4; i++) {
        int x = x1+moves[i];
        if (a[x] < 0)
            sets.insert(abs(a[x]));
    }
    if(sets.empty()) {
        mp[idx--].insert(x1);
    } else {
        set<int>::iterator it = sets.begin();
        it++;
        for(; it != sets.end(); it++)
            add(mp[-(*sets.begin())],mp[-(*it)],-(*sets.begin()));
        mp[-(*sets.begin())].insert(x1);
        sets.clear();
    }
}

void wave() {
    set<int> sets;
    for(int x = 1; x < n + 2; x++)
        for(int y = 1; y < m + 2; y++)
            if(a[x*(n+2)+y] == 0) {
                for(int i = 0; i < 4; i++) {
                    int x1 = x*(n+2)+y+moves[i];
                    if (a[x1] < 0)
                        sets.insert(abs(a[x1]));
                }
                if(sets.empty()) {
                    mp[idx--].insert(x*(n+2)+y);
                } else {
                    set<int>::iterator it = sets.begin();
                    it++;
                    for(; it != sets.end(); it++)
                        add(mp[-(*sets.begin())],mp[-(*it)],-(*sets.begin()));
                    mp[-(*sets.begin())].insert(x*(n+2)+y);
                    sets.clear();
                }
            print();
            }

}

int main() {
    freopen("tests/00","r",stdin);
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


    int ans = k;
    for(; ans > (a[m+3] == 0 ? k : (a[(n+1)*(m+1)-2] == 0 ? a[m+3] : min(a[m+3],a[(n+1)*(m+1)-2]))) ; ans--) {
        a[w[ans-1]] = 0;
    }
    a[m+3] = -1;
    wave();
    print();
    for(; ans >= 1 && a[(n+1)*(m+2)-2] != -1; ans--) {
        a[w[ans-1]] = 0;
        check_point(w[ans-1]);
    }
    cout << ans;

    return 0;
}
