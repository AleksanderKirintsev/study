#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
#define NLIM 15

struct wh{
    int w,h;
    };

bool operator< (wh& l, wh& r){
    return (l.w < r.w || (l.w == r.w && l.h < r.h));
}
int main() {
    srand(time(0));
    int n,ans;
    wh v[NLIM];
    for (int t = 0; t < 10;t++){
        n = 1 + rand() % NLIM;
        for (int i = 0; i < n; i++){
            v[i].w = 1 + rand() % 6;
            v[i].h = 1 + rand() % 5;

        }

        sort(v,v+n);

        cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << v[i].w << " " << v[i].h << endl;
        cin >> ans;
        cout << endl;

        ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
        infile << n << endl;
        for (int i = 0; i < n; i++)
            infile << v[i].w << " " << v[i].h << endl;
        infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << ans;
        afile.close();

    }
    return 0;
}
