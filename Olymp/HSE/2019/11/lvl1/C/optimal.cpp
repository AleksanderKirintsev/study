#include <iostream>
#include <set>
using namespace std;
#define X first
#define Y second
#define a(x,y) a[x*(m+2)+y]
#define b(x,y) b[x*(m+2)+y]

int n,m,*a,*b;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
pair<int,int> st;
pair<int,int> f;
set<pair<int,pair<int,int>>> s;

void F() {
    s.insert({1e9,st});
    while(!s.empty()){
        pair<int,pair<int,int>> v = *(s.begin());
        if(v.Y.X == f.X && v.Y.Y == f.Y)
            return;
        for(int i = 0; i < 4; i++){
            int *x = &a((v.Y.X+dx[i]),(v.Y.Y+dy[i]));int *y = &a((v.Y.X),(v.Y.Y));int *z = &b((v.Y.X+dx[i]),(v.Y.Y+dy[i]));
            if(*x - *y < *z || *z == -1){
                *z = ((*x - *y) <= 0 ? 0 : (*x - *y));
                s.insert({*z,{v.Y.X+dx[i], v.Y.Y+dy[i]}});
            }
        }
        s.erase(s.find(v));
    }
}
int main() {
    cin >> n >> m;
    a = new int[(n+2)*(m+2)];
    b = new int[(n+2)*(m+2)];
    fill_n(b,(n+2)*(m+2),-2);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> a(i,j);
            b(i,j) = -1;
        }

    cin >> st.X >> st.Y >> f.X >> f.Y;

    F();
    cout << b(f.X,f.Y);
    return 0;
}
