#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define X first
#define Y second
int n;
vector<set<int>> dst;
pair<int,int> p[2500];
int main() {
    cin >> n;
    dst.resize(n);

    for(int i = 0; i < n; i++)
        cin >> p[i].X >> p[i].Y;

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
                dst[i].insert((p[i].X-p[j].X)*(p[i].X-p[j].X)+(p[i].Y-p[j].Y)*(p[i].Y-p[j].Y));

    int q = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            int a = (p[i].X-p[j].X)*(p[i].X-p[j].X)+(p[i].Y-p[j].Y)*(p[i].Y-p[j].Y);
        }
    cout << q;
    return 0;
}
