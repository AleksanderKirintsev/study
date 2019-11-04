#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> *v;

int F(int x,int p){
    int q = 0;
    for(int y:v[x])
        if(y != p)
            q+=F(y,x);

    return q+1;
}

int main() {
    cin >> n;
    v = new vector<int>[n];
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }

    for(int i = 0; i < n; i++){
        int mx = 0;
        for(int x:v[i])
            mx = max(mx,F(x,i));
        cout << mx+1 << " ";
    }

    return 0;
}
