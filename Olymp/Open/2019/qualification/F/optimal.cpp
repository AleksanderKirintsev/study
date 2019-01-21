#include <iostream>
#include <bitset>
#include <map>
#include <algorithm>
using namespace std;
#define X first
#define Y second
const int NLIM = 1e6;
int n;
int *a,*b;

bool optimal() {
    map<int,int> m;
    bitset<NLIM> bs;
    bs.set();
    int *d = new int[n];
    for(int i = bs._Find_first(); i < n; i = bs._Find_first()) {
        int ind = -1;
        int q = 0;
        d[q++] = i;
        ind = (a[i] == b[i] ? 0 : ind);
        bs[i] = 0;
        for(int j = a[i]; j != i; d[q++] = j,j = a[j]) {
            ind = (j == b[i] ? q : ind);
            bs[j] = 0;
        }

        if(ind == -1)
            return 0;

        pair<int,int> pr[q];
        for(int j = 0; j < q; j++) {
            pr[j].X = d[j];
            pr[j].Y = d[(j + ind) % q];
        }

        sort(pr.begin(),pr.end());
        for(int j = 0; j < q; j++)
            if(px[j].Y != b[px[j].X])
                return 0;
        if(m[q] == 0 || m[q] == ind+1)
            m[q] == ind+1;
        else
            return 0;
        for(int j = 0; j < q; j++)
            cout << d[j] << " ";
        cout << endl;
    }
    for(auto i : m)

    return 1;
}

int main() {
    freopen("tests/08","r",stdin);
    cin >> n;

    a = new int[n];
    for (int i = 0; i < n; a[i++]--)
        cin >> a[i];

    b = new int[n];
    for (int i = 0; i < n; b[i++]--)
        cin >> b[i];

    cout << (optimal() ? "Yes" : "No");
    return 0;
}
