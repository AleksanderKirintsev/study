#include <iostream>
using namespace std;

int main()
{
    long long curr,prev;
    int n,h,m,s,q = 1;

    cin >> n;
    scanf("%d:%d:%d",&h,&m,&s);

    prev = h * 3600 + m * 60 + s;
    for (int i = 1; i < n; i++){
        scanf("%d:%d:%d",&h,&m,&s);

        curr = h * 3600 + m * 60 + s;
        q += (curr <= prev ? 1 : 0);
        prev = curr;
    }
    printf("%d",q);
    return 0;
}
