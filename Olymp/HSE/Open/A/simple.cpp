#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k, x, q;
    double a;
    cin >> n >> k >> x;//4 3 1
    a = double(x) / (n - k);
    if(a - int(a) < 0.000001)
        q = n*int(a);
    else{
        int c = (1 - (a - int (a))) * (n - k);
        q = (c * int (a)) + (n - c) * int (a+1);}
    cout << q;
    return 0;
}
