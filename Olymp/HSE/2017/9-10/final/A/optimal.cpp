#include <iostream>
using namespace std;
void fix (int &h, int &m, int &days) {
    h += m / 60;
    m %= 60;
    days += h / 24;
    h %= 24;
}

int main() {
    int hd, md, hf, mf, d, a, days = -2;
    cin >> hd >> md >> hf >> mf >> d >> a;

    fix (hd += hf, md += mf, days);
    fix (hd += (a - d) + 48, md, days);

    cout << hd << " " << md << " " << days;
    return 0;
}
