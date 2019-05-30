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
    int size(){
    return length;
    }

    int operator[](int index) {
        return a[index];
    }

    MyVector& operator= (const MyVector& value) {
        for(int i = 0; i < this->capacity; i++)
            a[i] = value.a[i];
        return *this;
    }
};
int main() {
    MyVector vec;
    vector<int> vect(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    //vec[0] = 5;
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];
//    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//        cout << *it;

    return 0;
}

