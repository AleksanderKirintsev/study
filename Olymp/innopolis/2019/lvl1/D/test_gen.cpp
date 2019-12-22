#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    int n = stoi(argv[1]),s = stoi(argv[2]), v = stoi(argv[3]);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,1e5);
    srand ( time ( NULL )* (stoi(argv[4])+1));

    cout << n << " " << s << " " << v << "\n";
    for(int i = 0; i < n-1; i++)
        cout << dis(gen) << " ";
    return 0;
}
