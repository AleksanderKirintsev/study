#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
#define SIZE 30
int main() {
    srand(time(0));
    int m,w,h,x,y,ans;
    for (int t = 4; t < 10; t++){
		m = 1 + rand() % 10;
		h = 1 + rand() % SIZE;
		w = 1 + rand() % SIZE;
		x = rand() % (SIZE+1);
		y = rand() % (SIZE+1);

		cout << m << '\n' << x << '\n' << y << '\n' << w << '\n' << h << '\n';
        cin >> ans;
        cout << endl;

		ofstream infile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) );
		infile << m << '\n' << x << '\n' << y << '\n' << w << '\n' << h << '\n';
		infile.close();

        ofstream afile ( "tests\\" + to_string ( t / 10 ) + to_string ( t % 10 ) + ".a" );
        afile << ans;
        afile.close();

    }
    return 0;
}
