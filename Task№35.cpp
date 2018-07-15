#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
srand(time(NULL));
const int N = 10;
int a[N];
int max,k=0;

for (int i = 0; i < N; ++i)
a[i] = 1 + rand()%10; // случайные числа от 1 до 10
max = a[0] + a[1] + a [2];

for (int i = 0; i < N; ++i)
cout << a[i] << " ";
cout << endl;

for (int i = 1; i < N-2; ++i)
if (a[i]+a[i+1]+a[i+2] > max) {

max = a[i]+a[i+1]+a[i+2];
k = i;
}
cout << a[k] << " " <<a[k+1] << " " << a[k+2];
return 0;
}

