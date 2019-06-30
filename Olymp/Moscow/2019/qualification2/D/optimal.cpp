#include <iostream>
#include <algorithm>
using namespace std;
int n,k,*a,*b;

int del(int c){
    int l = 0,r = k;
    while(l+1 < r){
        int mid = (l+r)/2;
        if(b[mid] > c)
            r = mid;
        else
            l = mid;
    }

    b[l] = 0;
    return l;
}
void add(int c,int idx){
    b[idx] = c;
    while(b[idx] < b[idx-1] && idx > 0){
        swap(b[idx],b[idx-1]);
        idx--;
    }
    while(b[idx] > b[idx+1] && idx < k-1){
        swap(b[idx],b[idx+1]);
        idx++;
    }
}
int main() {
    //freopen("tests/00","r",stdin);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> k;

    a = new int[n];
    b = new int[k];


    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < k; i++)
        b[i] = a[i];

    sort(b,b+k);

    for(int i = k; i < n; i++){
        cout << b[k/2] << " ";
        int idx = del(a[i-k]);
        add(a[i],idx);
    }
    cout << b[k/2] << " ";
    return 0;
}
