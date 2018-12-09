#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;
#define NLIM 15
struct ent {
    char c;
    int l,r;
};

int main() {
    srand(time(0));
    int n,q;

    for(int t = 3; t < 10; t++) {
        n = 1 + rand() % NLIM;
        q = 1 + rand() % NLIM;
        int a[n];
        ent b[q];

        for(int i = 0; i < n; i++)
            a[i] = rand() % 10;

        int j = 0;
        for(; j < q/5; j++) {
            b[j].c='!';
            b[j].l= 1 + rand() % n;
            b[j].r= 1 + rand() % n;
            if(b[j].l > b[j].r)
                swap(b[j].l,b[j].r);
        }
        for(; j < q; j++) {
            b[j].c = '?';
            b[j].l= 1 + rand() % n;
            b[j].r= 1 + rand() % n;
            if(b[j].l > b[j].r)
                swap(b[j].l,b[j].r);
        }
            random_shuffle(b,b+q);

            cout << n << " "<< q << endl;
            for(int i = 0; i < n; i++)
                cout << a[i] << " ";

            cout << endl;
            for(int i = 0; i < q; i++)
                cout << b[i].c << " " << b[i].l << " " << b[i].r << endl;

            int ans[q - q/5];
            for(int i = 0; i < q - q/5;i++)
                cin >> ans[i];

            ofstream infile ("tests/" + to_string (t / 10) + to_string (t % 10));
            infile << n << " " << q << endl;
            for (int i = 0; i < n; i++)
                infile << a[i] << " ";

            infile << endl;
            for(int i = 0; i < q; i++)
                infile << b[i].c << " " << b[i].l << " " << b[i].r << endl;

            infile.close();
        ofstream afile ("tests/" + to_string (t / 10) + to_string (t % 10) + ".a");
        for(int i = 0; i < q - q/5;i++)
            afile << ans[i]<<endl;
        afile.close();
    }
    return 0;
}


