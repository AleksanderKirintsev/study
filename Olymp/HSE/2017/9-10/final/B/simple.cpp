#include <iostream>
using namespace std;
struct Guests {
    int l, r, num;
};

istream& operator>> ( istream& is, Guests& a ) {
    cin >> a.l >> a.r;
}


int n;
Guests a[100000];

void msort(){
    for ( int i = 0; i < n - 1; i++ ) {
        int m = 1e9, num;
        for ( int j = i; j < n; j++ ) {
            if ( m > a[j].l ) {
                m = a[j].l;
                num = j;
            }
        }
        swap ( a[i].l, a[num].l );
        swap ( a[i].r, a[num].r );
        swap ( a[i].num, a[num].num );
    }
}

void nsort() {
    for ( int i = 0; i < n - 1; i++ ) {
        int m = 1e5, num;
        for ( int j = i; j < n; j++ ) {
            if ( m > a[j].num ) {
                m = a[j].num;
                num = j;
            }
        }
        swap ( a[i].l, a[num].l );
        swap ( a[i].r, a[num].r );
        swap ( a[i].num, a[num].num );
    }


}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    cin >> n;
    for ( int i = 0; i < n; i++){
        cin >> a[i];
        a[i].num = i + 1;
        }

    msort();

    for ( int i = 0; i < n - 1; i++ )
        for ( int j = i + 1; (j < n || a[j].l > a[i].r) ; j++ ){

        if (a[j].l <= a[i].r && a[j].r <= a[i].r){
            a[j].l = -1;
            a[j].r = -1;
            }

        if (a[j].l <= a[i].r && a[j].r > a[i].r){
            a[j].l = a[i].r + 1;

            }
    }

        //cout << a[i].l << " " << a[i].r << " " << a[i].num << endl;
    nsort();

        for ( int i = 0; i < n; i++)
        cout << a[i].l << " " << a[i].r << endl;
    return 0;
}
