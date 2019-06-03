#include <iostream>
using namespace std;
struct Int{
    int a;

    int operator=(int b){
        this->a = b;
        return this->a;
    }

    int operator+(Int& b){
        return this->a + b.a;
    }
    int operator*(Int& b){
       return this->a * b.a;
    }

    bool operator>(Int& b){
        return (this->a > b.a);
    }

    bool operator<(Int& b){
        return(this->a < b.a);
    }

    bool operator==(Int& b){
        return(this->a == b.a);
    }
};

istream & operator>>(istream & is, Int & n){
    cin >> n.a;
}

ostream & operator<<(ostream & os, Int & n){
    cout << n.a;
}

int main(){
    Int a,c;
//    cin >> a;
//    cin >> c;
    a = 6; c = 5;
    cout <<"a = " << a << ", c = " << c << endl;
    cout <<"a + c = " <<a + c << endl;
    cout <<"a * c = " <<a * c << endl;
    cout <<"a = " << a << endl;
    cout << "a + c" << endl;
    a = a+c;
    cout <<"a = " << a << endl;
    a = 5;

    cout <<"a = " << a << ", c = " << c << endl;
    cout << "(a > c) = " << (a > c) << endl;
    cout << "(a < c) = " << (a < c) << endl;
    cout << "(a == c) = " << (a == c) << endl;
    return 0;
}

