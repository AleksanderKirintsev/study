#include <iostream>
using namespace std;

struct deque {
    int *head,*tail;
    int lenght_back,lenght_front;

    struct Node {int a[2]={};Node *prev,*next;};;
    Node *first,*second;


    deque() {
        first = second = new Node;
        first->next = first->prev = NULL;
        head = tail = first->a;
        lenght_back = lenght_front = 0;
    }
    void push_back(int value){
        if(lenght_back % 2 == 0 && lenght_back){
            second->next = new Node;
            second->next->prev = second;
            second = second->next;
            tail = second->a;
        }
        *tail = value;
        tail++;
        lenght_back++;
    }
    void push_front(int value){
        if(lenght_front % 2 == 0){
            first->prev = new Node;
            first->prev->next = first;
            first = first->prev;
            head = first->a+1;
        }
        *head = value;
        head--;
        lenght_front++;
    }
};

int main() {
    deque dq;
    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(1);
    dq.push_back(2);
}
