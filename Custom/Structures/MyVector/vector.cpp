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

    MyVector& operator=(MyVector& vec) {
        this->length = vec.size();
        while(length > capacity) {
            capacity *= 2;
            int *b = new int[capacity];
            memcpy(b,a,length * sizeof(int));
            delete a;
            a = b;
        }

        for(int i = 0; i < length; i++)
            a[i] = vec[i];

        return *this;
    }


};
int main() {
    MyVector vec,vec1(4);

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec[0] = 1;vec[1] = 2;vec[2] = 3;
    vec1[0] = 4;vec1[1] = 5;vec1[2] = 6;vec1[3]=7;

    vec = vec1;
    vec[0] = 3;

    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];
    cout << endl;
    for(int i = 0; i < vec1.size(); i++)
        cout << vec1[i];
//    for(MyVector::iterator it = vec.begin(); it != vec.end(); it++)
//        cout << *it;

    return 0;
}

