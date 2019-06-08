#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct MyVector {
    int *a;
    int capacity;
    int length;


    MyVector() {
        capacity = 2;
        a = new int[capacity];
        length = 0;
    }

    MyVector(int capacity) {
        this->capacity = capacity;
        a = new int[this->capacity] {};
        length = this->capacity;
    }

    void push_back(int value) {
        if(length == capacity) {
            capacity *= 2;
            int *b = new int[capacity];
            memcpy(b,a,length * sizeof(int));
            delete a;
            a = b;
        }
        a[length++] = value;
    }

    int size() {
        return length;
    }

    int& operator[](int index) {
        return a[index];
    }


    struct Iterator{
        int *it;
        Iterator(int* first){
            it = first;
        }

        int operator+ (int n) {return *(it+n);}
        int operator- (int n) {return *(it-n);}

        int operator++ (int) {return *it++;}
        int operator-- (int) {return *it--;}
        int operator++ () {return *++it;}
        int operator-- () {return *--it;}

        bool operator!= (const Iterator& iter) { return it != iter.it;}
        bool operator== (const Iterator& iter) { return it == iter.it;}
        int operator* () {return *it;}
    };
    Iterator begin(){return a;}
    Iterator end(){return a+length;}

};
int main() {
    MyVector vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec[0] = 5;

    for(MyVector::Iterator it = vec.begin(); it != vec.end(); it++)
            cout << *it;

    return 0;
}

