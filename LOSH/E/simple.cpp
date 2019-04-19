#include <iostream>

using namespace std;

int main(){
    long double x1,y1,x2,y2,k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    printf("%.10Lf %.10Lf",(x1+k*x2)/(1+k),(y1+k*y2)/(1+k));
    return 0;
}
