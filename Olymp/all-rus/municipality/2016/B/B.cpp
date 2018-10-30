#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n, a, b, c;
    cin >> n >> a >> b >> c;
    double sum = 2 * c, kol = n - 1;

    sum += sqrt (pow (a * kol, 2) + pow (b, 2)) + (sqrt (pow (a, 2) + pow (b, 2)) * kol) + b * kol;

    printf("%0.2f", sum);
    return 0;
}
