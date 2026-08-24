#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class QueueLinkList{
    Node* front;
    Node* back;
    int currSize;
    public:

    QueueLinkList(){
        front = back = nullptr;
        currSize = 0;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(isEmpty()){
            front = back = newNode;
        }else{
            back->next = newNode;
            back = newNode;
        }
        currSize++;
    }

    int pop(){
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int val = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr){
            back = nullptr;
        }
        delete temp;
        currSize--;
        return val;
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    int size() {
       return currSize;
    }
};