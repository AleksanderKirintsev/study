#include <iostream>
using namespace std;
const int SEC_PER_DAY = 24*3600;
struct Time {
    int h,m,s;
};

istream& operator>> ( istream& is, Time& t) {
    char c;
    return is >> t.h >> c >> t.m >> c >> t.s;
}
ostream& operator<< ( ostream& os, const Time& t) {
    char buffer[8];
    sprintf(buffer,"%02d:%02d:02d", t.h, t.m, t.s);
    return os << buffer;
}

Time a,b,c;
int ttos(Time& t) {
    return t.h*3600+t.m*60+t.s;
}
Time stot(int s) {
    return {s/3600,s%3600/60,s%60};
}
int main() {
    cin >> a >> b >> c;
    int aa,bb,s3;
    aa = ttos(a),bb = ttos(b),s3 = ttos(c);
    s3+=(aa > s3 ? SEC_PER_DAY : 0);
    b = stot((bb + (s3-aa)/2)% SEC_PER_DAY);

    cout << b;
    return 0;
}
