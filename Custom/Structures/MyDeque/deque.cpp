#include <iostream>
#include <cstring>
using namespace std;

struct deque {
    int **a,*head,*tail,*h,*t,length,length_h,length_t,capacity,capacity_h,capacity_t;
    int lim = 8/sizeof(int);

    deque() {
        a = new int*[capacity = length = 2];
        a[0] = new int[capacity_h = 2];
        a[1] = new int[capacity_t = 2];
        head = a[0];
        tail = a[1];
        h = a[0]+capacity-1;
        t = a[1];
        length_h = length_t = 0;
    }
    void push_back(int value) {
        if(capacity_t < lim && capacity_t == length_t) {
            capacity_t *=2;
            int *b = new int[capacity_t];
            memcpy(b,a[1],sizeof(int) * length_t);
            delete a[1];
            a[1] = b;
            t = a[1]+length_t-1;
        } else if(length_t % capacity_t == 0 && length_t) {
            if((a+capacity-1) < tail){
                capacity *= 2;
                int **b = new int[capacity];
                memcpy(b,a,sizeof(int*)*(length));
                delete a;
                a = b;
                head = a;
                tail = a+length-1;
                h = head+(capacity_h - 1 - length_h%capacity_h);
            }
            tail++;
            t = tail;
            length++;
        }
        *t = value;
        t++;
        length_t++;
    }

    void push_front(int value) {
        if(capacity_h < lim && capacity_h == length_h) {
            capacity_h*=2;
            int *b = new int[capacity_h];
            memcpy(b+length_h,head[0],sizeof(int) * length_h);
            delete head[0];
            head[0] = b;
            h = b+length_h-1;
        } else if(length_h % capacity_h == 0 && length_h) {
            head.push_back(new int[capacity_h]);
            h = head[0]+capacity_h-1;
        }
        *h = value;
        h--;
        length_h++;
    }

    void pop_back() {
        if(t < tail.back() && ) {
            tail.pop_back();
            t = tail.back
        }
        t--;
        lb--;
    }

    void pop_front() {
        if(h == head->a+capacity_f-1 && lf) {
            head = head->next;
            delete head->prev->a;
            delete head->prev;
            h = head->a-1;
        }
        h++;
        lf--;
    }
};

int main() {
    deque dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.pop_front();
    dq.pop_front();
    dq.pop_front();
    dq.pop_front();
}
