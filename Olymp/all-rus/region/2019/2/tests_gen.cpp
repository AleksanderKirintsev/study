#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main() {
    srand (time (0));
    int k;
    string ans;
    for (int t = 3; t < 7; t++) {
        k = -20 + rand() % 41;
        cout << k <<endl;
        cin >> ans;

        ofstream infile ("tests/" + to_string (t / 10) + to_string (t % 10));
        infile << k;
        infile.close();

        ofstream afile ("tests/" + to_string (t / 10) + to_string (t % 10) + ".a");
        afile << ans;
        afile.close();
    }
    return 0;
}
