#include <iostream>
using namespace std;

struct quad {
    int x,y,x1,y1;
};
quad f(quad c) {
    if(c.x1 >= c.x && c.y1 < c.y) {
        swap(c.y1,c.y);
        return c;
    }
    if(c.x > c.x1 && c.y <= c.y1) {
        swap(c.x1,c.x);
        return c;
    }
    if(c.x > c.x1 && c.y > c.y1) {
        swap(c.x1,c.x);
        swap(c.y1,c.y);
        return c;
    }
    return c;
}

bool Q(quad a,quad b) {
    bool A = (a.x <= b.x1 && a.x1 >= b.x && a.y <= b.y1 && a.y1 >= b.y);

    return (A);
}
int main() {
    quad a,b;
//      a.x,a.y,ax1,ay1,b.x,b.y,bx1,by1
    cin >> a.x >> a.y >> a.x1 >> a.y1 >> b.x >> b.y >> b.x1 >> b.y1;
    a = f(a);
    b = f(b);
    cout << (Q(a,b) ? "Yes" : "No");
    return 0;
}
