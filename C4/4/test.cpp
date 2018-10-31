#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

#define NLIM 15
#define Q first
#define M second

struct TR {
    int q;
    double p, m;
};

int n, q = 0, mq = 1, ans = 1;
double a[NLIM];

TR simple () {
    TR r = {0, 0, 1e6};

    for (int c = 1; c < (1 << n); c++) {
        int q = __builtin_popcount (c);
        double p = 1, m = 1e6;

        for (int i = 0; i < n; i++) {
            if ( (c & (1 << i)) > 0) {
                p *= a[n-i-1];
                m = min (a[n-i-1], m);
            }
        }

        if (p > r.p || (p == r.p && q < r.q))
            r = {q, p, m};

    }
    return r;
}


TR optimal() {
    TR r = {0,1,1e6 + 1};
    double z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1.0000000) {
            r.p *= a[i];
            r.q++;
            r.m = min (a[i], r.m);
        } else
            z = max (a[i], z);

    }
    if (r.m == 1e6 + 1) {
        r.q = 1;
        r.m = z;
        r.p = z;
    }
    return r;
}

int main() {
    srand (time (0));
    int c, b;
    for (int t = 0; t < 5000; t++) {

        n = 3 + rand() % (NLIM - 2);

        for (int i = 0; i < n; i++) {
            a[i] = double(rand()) / 10;
        }

        TR sim = simple();
        TR opt = optimal();

        if (sim.q != opt.q || sim.m != opt.m || sim.p != opt.p  ) {
            /*
            ofstream fout("error.txt");

            fout << n << endl;
            for (int i = 0; i < n; i++)
                fout << a[i] << endl;

            fout << endl;

            fout << "simple " << sim.q << " " << sim.m << endl;
            fout << "optimal " << opt.Q << " " << opt.M << endl;
            fout.close();
            */
            cout <<"error!" << endl;

            return 0;
        }


    }
    cout << "done!" << endl;
    return 0;
}
