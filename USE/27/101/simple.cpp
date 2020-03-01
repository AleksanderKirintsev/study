#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
#define ALIM 20
#define NLIM 10
int main() {
    int f,t;
    cin >> f >> t;
    int d[max(f,t)+1] = {0};
    d[f] = 1;
    for(int i = f+1; i <= t; i++){
        d[i]+=d[i-1];
        d[i]+= (i%3 == 0 ? d[i/3] : 0);
        d[i]+= (i%4 == 0 ? d[i/4] : 0);

    }
    for(int i = f; i <= t; i++)
        cout << i << " <> " << d[i] << "\n";
    return 0;
}
