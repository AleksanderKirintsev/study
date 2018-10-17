#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#define NLIM 7
#define Q first
#define M second

struct TR {
    int q;
    double p, m;
};

int n, q = 0, mq = 1,ans = 1;
double a[NLIM];

TR simple () {
    TR r = {0, 0, 1e6};

    for (int c = 1; c < (1 << n); c++) {
        int q = __builtin_popcount (c);
        double p = 1, m = 1e6;

        for (int i = 0; i < n; i++) {
            if ( (c & (1 << i)) > 0) {
                p *= a[i];
                m = min (a[i], m);
            }
        }

        if (p > r.p || (p == r.p && q < r.q))
            r = {q, p, m};

    }
    return r;
}


pair<int,double> optimal() {
   pair<int,double> r = {0, 1e6};
   int z = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( a[i] > 1.0000000 ) {
            r.Q++;
            r.M = min ( a[i], r.M );
        } //else
            //z = max ( a[i], z );

    }
    //if (smin == 1e6 + 1) ans  = 1;
    return r;
}

int main() {
    srand(time(0));
    int c, b;
    for (int t = 0; t < 10000; t++){

    n = 3 + rand()% (NLIM - 2);

    for (int i = 0; i < n; i++){
        string s;
        c = rand() % 11;
        b = rand() % 10;
        s += to_string(c);
        s += ".";
        s += to_string(b);
        a[i] = atof(s.c_str());
        }

        TR sim = simple();
        pair<int,double> opt = optimal();

        if (sim.q != opt.Q || sim.m != opt.M ){
            cout << t << " error!";
            return 0;
        }


    }
    cout << "done!";
    return 0;
}
