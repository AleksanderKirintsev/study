#include <iostream>
using namespace std;
#define X first
#define Y second
typedef pair<int,int> point;
typedef pair<int,int> vec;

int n;
point *p;
bool f(int a,int b,int c){
    vec ab,ac;
    ab ={p[b].X-p[a].X,p[b].Y-p[a].Y};
    ac ={p[c].X-p[a].X,p[c].Y-p[a].Y};
    return (ab.X*ac.X+ab.Y*ac.Y == 0);
}
int main() {
    cin >> n;
    p = new point[n];
    for(int i = 0; i < n; i++)
        cin >> p[i].X >> p[i].Y;

    int q = 0;
    for(int a = 0; a < n - 2; a++)
        for(int b = a+1; b < n - 1; b++)
            for(int c = b+1; c < n; c++)
                q+= f(a,b,c)+f(b,a,c)+f(c,a,b);
    cout << q;
    return 0;
}
