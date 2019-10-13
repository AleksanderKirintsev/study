#include <iostream>
#include <iomanip>
using namespace std;
const int DAY = 24*3600;
struct Time {
    int h,m,s;
};

istream& operator>> ( istream& in, Time& t) {
    char c;
    return in >> t.h >> c >> t.m >> c >> t.s;
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
    int s1,s2,s3;
    s1 = ttos(a),s2 = ttos(b),s3 = ttos(c);
    s3+=(s1>s3 ? DAY : 0);
    s2 = (s2 + (s3-s1)/2)% DAY;
    printf("%02d:%02d:%02d",s2/3600,s2%3600/60,s2%60);
    return 0;
}
