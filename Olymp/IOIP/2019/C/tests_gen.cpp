#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc,char **argv){
    srand(time(0)*atoi(argv[2]));
    int n = atoi(argv[1]);

    for(int i = 0; i < n; i++)
        printf("%03d",rand() % 1000);


    return 0;
}
