#include <iostream>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <bitset>
using namespace std;
bitset<500> bs;
deque<int> q;

int main(int argc,char **argv){
    srand(time(0)*(atoi(argv[2])+1));
    int n = atoi(argv[1]);
    cout << n << "\n";
    int r = n-1;
    q.push_back(rand()% n);
    while(r > 0){
        int v = q.front();
        q.pop_front();
        bs[v] = 1;
        int c = rand()%r;
        c += (c == 0);
        r-=c;
        for(int i = 0; i < c; i++){
            int v1 = rand() % n;
            while(bs[v1] == 1){
                v1++;
                v1 %= n;
            }
            bs[v1] = 1;
            q.push_back(v1);
            if(rand()%2 == 0)
                cout << v+1 << " " << v1+1 << "\n";
            else
                cout << v1+1 << " " << v+1 << "\n";
        }
    }

    return 0;
}
