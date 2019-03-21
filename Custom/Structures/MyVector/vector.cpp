#include <iostream>
#include <cstring>
using namespace std;

struct MyVector {
    int *a;
    int capacity;
    int size;

    MyVector() {
        capacity = 2;
        a = new int[capacity];
        size = 0;
    }

    void push_back(int value) {
        if(size == capacity) {
            capacity *= 2;
            int *b = new int[capacity];
            memcpy(b,a,size * sizeof(int));
            delete a;
            a = b;
        }
        a[size++] = value;
    }

    void change(int index, int value) {
        a[index] = value;
    }

    int get_value(int index) {
        return a[index];
    }
};
int main() {
    MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.change(1,5);
    for(int i = 0; i < 3; i++)
        cout << v.get_value(i) << " ";
    return 0;
}

