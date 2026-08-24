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
    }
};

class myStack{
    Node* top;
    int count;

    public:

    myStack(){
        top = NULL;
        count = 0;
    }

    void pop(int data){
        Node* newNode = new Node(data);
        newNode -> next = top;
        top = newNode;

        count++;
    }

    int pop(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }

        Node* temp = top;
        top = top->next;
        count --;
        int val = temp->data;
        delete temp;
        return val;
    }

    int peek(){
        if(top == NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty(){
        return top==NULL;
    }

    int size(){
        return count;
    }
};