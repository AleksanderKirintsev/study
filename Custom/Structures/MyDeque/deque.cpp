#include <iostream>
#include <cstring>

using namespace std;

struct deque {
    int *a,*h,*t,capacity = 1,length = 0;
    deque() {
        a = new int [capacity] {};
        h = t = a;
    }
    void push_back(int value) {
        if(a+capacity <= t) {
            capacity*=2;
            int *b = new int[capacity]{};
            memcpy(b,a,length*sizeof(int));
            delete a;
            a = b;
            h = a;
            t = a+length;
        }
        *t = value;
        t++;
        length++;
    }
    void push_front(int value) {
        if(a > h) {
            capacity*=2;
            int *b = new int[capacity]{};
            memcpy(b+capacity/2,h,length*sizeof(int));
            delete a;
            a = b;
            h = a+capacity/2;
            t = h+length;
        }
        h--;
        *h = value;
        length++;
    }
    void pop_back() {
        if(length == capacity/4){
            capacity /= 4;
            int *b = new int[capacity]{};
            memcpy(b,h,length*sizeof(int));
            delete a;
            a = b;
            h = a;
            t = a+length;
        }
        t--;
        length--;
    }
    void pop_front() {
        if(length == capacity/4){
            capacity /= 4;
            int *b = new int[capacity]{};
            memcpy(b,h,length*sizeof(int));
            delete a;
            a = b;
            h = a;
            t = a+length;
        }
        h++;
        length--;
    }
    int front(){return *h;}
    int back( ){return *t;}
    int size( ){return length;}
    int& operator[](int idx){return *(h+idx);}
};

int main() {
    deque dq;
    for(int i = 1; i <= 20; i++)
        dq.push_front(i);
    for(int i = 1; i <= 19; i++)
        dq.pop_front();
    cout<< dq[0];
}
