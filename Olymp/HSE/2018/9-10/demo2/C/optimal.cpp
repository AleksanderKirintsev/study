#include <iostream>
#include <algorithm>
using namespace std;

#define W first
#define H second
#define ll long long

int n;
pair<int, int> a[100000];

int main() {
    cin.tie (0);
    cin.sync_with_stdio (0);
    cout.tie (0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].W >> a[i].H;

    sort (a, a + n, [](const pair<int,int> &l, const pair<int,int> &r) {return l > r;});

    ll sum = a[0].H;
    for (int i = 0; i < n;i++)
        sum += (a[i].W < a[i - 1].W ? a[i].H : 0);

    cout << sum;
    return 0;
}
