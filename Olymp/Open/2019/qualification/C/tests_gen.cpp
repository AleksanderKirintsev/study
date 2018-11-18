#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

int main() {
    srand (time (0));
    int n, p, k, ans;
    for (int t = 2; t < 7; t++) {
        n = 1 + rand() % 7;
        p = rand() % 11;
        k = 1 + rand() % 10;
        int a[n];

        cout << n << " " << p << " " << k << endl;
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 11;
            cout << a[i] << " ";
        }

        cout << endl;
        cin >> ans;

        ofstream infile ("tests/" + to_string (t / 10) + to_string (t % 10));
        infile << n << " " << p << " " << k << endl;
        for (int i = 0; i < n; i++)
            infile << a[i] << " ";
        infile.close();

        ofstream afile ("tests/" + to_string (t / 10) + to_string (t % 10) + ".a");
        afile << ans;
        afile.close();
    }
    return 0;
}
