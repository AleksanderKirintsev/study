#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
#define NLIM 12
int main() {
    srand (time (0));
    int n,m;

    for (int t = 3; t < 7; t++) {
        n = NLIM - rand() % (NLIM/2);
        m = NLIM - rand() % (NLIM/2);

        int a[m],b[n];
        for (int i = 0; i < m; i++)
            a[i] = 1 + rand() % n;
        for (int i = 0; i < n; i++)
            b[i] = 1 + i;
        random_shuffle(b,b+n);

        cout << n << " " << m << endl;
        for (int i = 0; i < m; i++)
            cout << a[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        int q;
        cin >> q;
        int ans[q];
        for(int i = 0; i < q; i++)
            cin >> ans[q];

        ofstream infile ("tests/" + to_string (t / 10) + to_string (t % 10));
        infile << n << " " << m << endl;
        for (int i = 0; i < m; i++)
            infile << a[i] << " ";
        infile << endl;
        for (int i = 0; i < n; i++)
            infile << b[i] << " ";
        infile.close();

        ofstream afile ("tests/" + to_string (t / 10) + to_string (t % 10) + ".a");
        afile << q << endl;
        for(int i = 0; i < q; i++)
            afile << ans[q] << " ";
        afile.close();
    }
    return 0;
}
