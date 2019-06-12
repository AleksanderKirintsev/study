#include <iostream>
#include <cstring>
using namespace std;

template<typename T> struct vector {
    T *a;
    int capacity;
    int length;

    vector() {
        capacity = 2;
        a = new T[capacity];
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

    int size() {return length;}

    T& operator[](int index) {return a[index];}


    struct Iterator{
        T *it;
        Iterator(T* first){it = first;}

        Iterator operator++ () {return ++it;}
        T operator* () {return *it;}
        bool operator!= (const Iterator& iter) {return it != iter.it;}
    };
    Iterator begin(){return a;}
    Iterator end(){return a+length;}

};

int main() {
    vector<char> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3.5);
    v[0] = 5.6;

    for(auto x:v)
        cout << x << " ";

    return 0;
}


