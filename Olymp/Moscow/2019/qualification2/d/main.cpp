#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n,k,a;
int main(){
    cin >> n >> k;
    deque<int> d;

    for (int i = 0; i < k; i++){
        cin >> a;
        d.push_back(a);
    }
    for(int i = 0; i < n-k; i++){
        sort(d.begin(),d.end());
        for(int j = 0; j < d.size(); j++)
            cout << d[j] << " ";
        cout << endl;
        //cout << d[k/2] << " ";
        d.pop_front();
        cin >> a;
        d.push_back(a);
    }
    return 0;
}
