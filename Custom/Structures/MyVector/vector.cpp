#include <iostream>
#include <cstring>
using namespace std;

template<typename T> struct vector {
    T *a;
    int capacity;
    int length;

    vector():vector(2) {
        length = 0;
    }

    vector(int capacity) {
        this->capacity = length = capacity;
        a = new T[capacity] {};
    }

    void push_back(T value) {
        if(length == capacity) {
            capacity *= 2;
            T *b = new T[capacity];
            memcpy(b,a,length * sizeof(T));
            delete a;
            a = b;
        }
        a[length++] = value;
    }
    void pop_back() {
        length--;
        if(length == capacity/4) {
            capacity /= 4;
            T *b = new T[capacity];
            memcpy(b,a,length * sizeof(T));
            delete a;
            a = b;
        }
    }
    int size() {return length;}

    T& operator[](int index) {return a[index];}

    struct iterator{
        T *it;
        iterator(T* first){it = first;}

        iterator operator++ () {return ++it;}
        T operator* () {return *it;}
        bool operator!= (const iterator& iter) {return it != iter.it;}
    };
    iterator begin(){return a;}
    iterator end(){return a+length;}

};

int main() {
    vector<int> v;
    for(int i = 0; i < 9; i++)
        v.push_back(i+1);
    for(int i = 0; i < 7; i++)
        v.pop_back();

    for(auto x:v)
        cout << x << " ";

    return 0;
}


