#include <iostream>
using namespace std;

int optimal(int n,int k) {
    if (n == 0)
        return 1;

    int sum = 0;
    for(int i = 1; i < k; ++i)
        if(n-i >=0)
            sum += optimal(n-i,i);

    return sum;
}

int simple(int n,int k) {
    if (n == 0)
        return 1;
    else if(k == 0)
        return 0;

    int sum = 0;
    for(int i = k; i > 0; --i)
        sum += simple(n-i,i-1);

    return sum;
}

int main() {
    for(int i = 1;i <= 27; i++)
        if(optimal(i,i+1) != simple(i,i+1)){
            cout << "error!";
        }
        cout << "done!";
    return 0;
}
