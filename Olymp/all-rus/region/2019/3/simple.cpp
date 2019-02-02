#include <iostream>
#include <deque>
#include <set>
using namespace std;
int n,m;
deque<int>a,b;

int main() {
    cin >> n >> m;
    a.resize(m);
    b.resize(n);
    int d[n+1] = {0},q = 0,ans[m] = {0};
    set<int> prev;

    for(int i = 0; i < m; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    while(!a.empty()) {
        prev.clear();
        if (d[b[0]] != 0) {
            if(a[0] != b[0]) {
                for(int i = 0; i < a.size(); i++) {
                    if (a[i] == b[0])
                        break;
                    prev.insert(a[i]);
                }

                int bs = b[0],j;
                for(j = 1; !prev.empty(); j++) {
                    if(prev.find(b[j])!= prev.end())
                        prev.erase(b[j]);
                    b[j-1] = b[j];
                }

                b[j] = bs;
                d[a[0]]--;
                ans[q] = j;
                a.pop_front();

            } else {
                if(d[b[0]] == 1) {
                    d[b[0]]--;
                    ans[q] = n;
                    b.push_back(b[0]);
                    b.pop_front();
                    a.pop_front();
                } else {
                    int k = n,bs = b[0];
                    for(int j = 1; j < n; j++)
                        if(a[j] == b[0]) {
                            k = j+1;
                            break;
                        }
                    for(int j = 1; j < k; j++)
                        b[j-1] = b[j];



                    d[b[0]]--;
                    ans[q] = k;
                    b[k] = bs;
//                    cout << endl;
//                    for(int j = 0; j < b.size(); j++)
//                        cout << b[j] << " ";
//                    cout << endl;
                    a.pop_front();
                }
            }
        } else {
            b.pop_front();
            ans[q] = n;
        }
        q++;
    }

    cout << q << endl;
    for(int i = 0; i < q; i++ )
        cout << ans[i] << " ";
    return 0;

}
