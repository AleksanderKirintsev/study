#include <iostream>
#include <cstring>
using namespace std;

struct deque {
    int *start,*stop;
    int lb,lf,capacity_b,capacity_f;
    int lim = 8/sizeof(int);
    struct Node {int *a;Node *prev,*next;};
    Node *head,*tail;

    deque() {
        head = new Node;tail = new Node;
        head->next = tail; head->prev = NULL;
        tail->next = NULL; tail->prev = head;
        capacity_b = capacity_f = 2;
        head->a=new int[capacity_f]; tail->a=new int[capacity_b];
        start = head->a+capacity_f; stop = tail->a;
        lf = lb = 0;
    }
    void push_back(int value) {
        if(capacity_b < lim && capacity_b == lb) {
            capacity_b*=2;
            int *b = new int[capacity_b];
            memcpy(b,tail->a,sizeof(int) * lb);
            delete tail->a;
            tail->a = b;
            stop = tail->a+lb;

        } else if(lb % capacity_b == 0 && lb) {
            tail->next = new Node;
            tail->next->prev = tail;
            tail = tail->next;
            tail->a=new int[capacity_f];
            stop = tail->a-1;
        }
        stop++;
        *stop = value;
        lb++;
    }
    void push_front(int value) {
        if(capacity_f < lim && capacity_f == lf) {
            capacity_f*=2;
            int *f = new int[capacity_f];
            memcpy(f+lf,head->a,sizeof(int) * lf);
            delete head->a;
            head->a = f;
            start = head->a+lf-1;
        } else if(lf % capacity_f == 0 && lf) {
            head->prev = new Node;
            head->prev->next = head;
            head = head->prev;
            head->a=new int[capacity_f];
            start = head->a+capacity_f;
        }
        start--;
        *start = value;
        lf++;
    }
    void pop_back(){
        if(stop == tail->a && lb){
            tail = tail->prev;
            delete tail->next->a;
            delete tail->next;
            stop = tail->a+capacity_b+1;
        }
        stop--;
        lb--;
    }
    void pop_front(){
        if(start == head->a+capacity_f-1 && lf){
            head = head->next;
            delete head->prev->a;
            delete head->prev;
            start = head->a-1;
        }
        start++;
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
