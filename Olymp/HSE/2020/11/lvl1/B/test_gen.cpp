#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    int n = stoi(argv[1]),k = stoi(argv[2]);

    pair<int,int> *b = new pair<int,int>[n];
    srand ( time ( NULL )* (stoi(argv[3])+1));
    for(int i = 0; i < n; i++){
        b[i].first = rand();
        b[i].second = rand();
    }

    cout << n << " " << k << "\n";
    for(int i = 0; i < n; i++)
        cout << b[i].first << " " << b[i].second << "\n";

    return 0;
}
