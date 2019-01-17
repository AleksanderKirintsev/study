#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
#define NLIM 15

int main() {
    srand(time(0));
    
    for (int t = 0; t < 10;t++){
		ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
		infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile.close();

    }
    return 0;
}
