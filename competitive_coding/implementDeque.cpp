/// implementing deque (deck) using circular array
#include<bits/stdc++.h>
using namespace std;

#define MAX 100

class Deque{
private:
    int arr[MAX];
    int front;
    int rear;
    int size;
public:
    Deque(int size){
        front = -1;
        rear = 0;
        this->size = size;
    }

    void insertFront(int key);
    void insertRead(int key);
    void deleteFront();
    void deleteRear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();

};

bool Deque::isFull(){
    return ((front == 0 && rear == size-1) || (front == rear+1));
}

bool Deque::isEmpty(){
    return (front == -1);
}

void Deque::insertFront(int key){
    if(isFull()){
        cout<<"Overflow!!!"<<endl;
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    } else if (front == 0) front = size-1;
    else front = front - 1;
    arr[front] = key;
}

void Deque::insertRead(int key){
    if(isFull()){
        cout<<"Overflow!!!"<<endl;
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    } else if (rear == size-1) rear = 0;
    else rear = rear+1;
    arr[rear] = key;
}

void Deque::deleteFront(){
    if(isEmpty()){
        cout<<"Underflow!!!"<<endl;
        return;
    }
    // only 1 element in the deque
    if(front == rear){
        front = -1;
        rear = -1;
    } else if (front == size-1) {
        front = 0;
    } else {
        front += 1;
    };
}

void Deque::deleteRear(){
    if(isEmpty()){
        cout<<"Underflow!!!"<<endl;
        return;
    }
    // only 1 element in the deque
    if(front == rear){
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size-1;
    } else {
        rear -= 1;
    };
}

int Deque::getFront(){
    if(isEmpty()){
        cout<<"Underflow!!!"<<endl;
        return -1;
    }
    return arr[front];
}

int Deque::getRear(){
    if(isEmpty()){
        cout<<"Underflow!!!"<<endl;
        return -1;
    }
    return arr[rear];
}

int main(){

    return 0;
}
