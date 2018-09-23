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

void my_sort() {
    for ( int i = 0; i < n - 1; i++ ) {
        int m = 1000000000, num = i;
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
};

/*void sort_by_num() {
    for ( int i = 0; i < n - 1; i++ ) {
        int m = 100000, num = i;
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
};*/
void sort_by_num() {
    for ( int i = 0; i < n; i++ ) {
        int num = a[i].num;
        swap ( a[i].l, a[num].l );
        swap ( a[i].r, a[num].r );
        swap ( a[i].num, a[num].num );
    }
};


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);

    int l, r,j = 1;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
        a[i].num = i;
    }

    //l = a[0].l;
    //r = a[0].r;

    my_sort();
    for(int i = 1; i < n;i++){
        if (a[i].l <= a[j-1].r)
            a[i].l = a[j-1].r+1;
        if (a[i].r <= a[j-1].r){
            a[i].r = -1;
            a[i].l = -1;
        j = i-1;
        i++;
        }else
            j = i;

        }



    sort_by_num();

    for ( int i = 0; i < n; i++ )
        cout << a[i].l << " " << a[i].r << " " <<  '\n' ;




    return 0;
}
