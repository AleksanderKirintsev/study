#include <iostream>
using namespace std;

string s;
char c[5][5];
int p[5][5];
int f(int i, int j,int a){
    int sum = 0;
    if(a == s.size())
        return 1;
    if(i-1 >=0 && c[i-1][j] == s[a] && p[i-1][j] == 0){
        p[i-1][j] = 1;
        sum += f(i-1,j,a+1);
    }
    if(j+1 <=5 && c[i][j+1] == s[a] && p[i][j+1] == 0){
        p[i][j+1] = 1;
        sum+= f(i,j+1,a+1);
    }
    if(i+1 <=5 && c[i+1][j] == s[a] && p[i+1][j] == 0){
        p[i+1][j] = 1;
        sum+= f(i+1,j,a+1);
    }
    if(j-1 >=0 && c[i][j-1] == s[a] && p[i][j-1] == 0){
        p[i][j-1] = 1;
        sum+= f(i,j-1,a+1);
        }
    p[i][j] = 0;
    return sum;
}

int main() {
    cin >> s;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> c[i][j];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(c[i][j] == s[0]){
                p[i][j] = 1;
                if(f(i,j,1)){
                    cout << "YES";
                    return 0;
                    }
                p[i][j] = 0;
        }
    cout << "NO";
    return 0;
}
