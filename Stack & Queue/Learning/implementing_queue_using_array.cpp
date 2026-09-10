#include <iostream>
using namespace std;

class QueueWithArray{
    public: 
    int* queueArray;
    int currPos, outQue, currSize, capacity;

    QueueWithArray() {
        queueArray = new int[10];
        currPos = -1;
        outQue = -1;
        currSize = 0;
        capacity = 10;
    }

    bool isEmpty(){
        return currSize == 0;
    }

    void push(int data){
        if(currSize >= capacity){
            cout << "Queue Overflow" << endl;
            return;
        }
        if(currPos == -1){
            currPos++;
        }else{
            currPos = (currPos + 1) % capacity;
        }
        queueArray[currPos] = data;
        currSize++;
        if(outQue == -1){
            outQue = 0;              
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "Empty Queue" << endl;
            return -1;
        }
        int poppedValue = queueArray[outQue];
        if(currSize == 1){
            outQue = -1;
            currPos = -1;
        }else{
            outQue = (outQue + 1) % capacity;
        }
        currSize--;
        return poppedValue;
    }

    int top(){
        if(isEmpty()){
            cout << "Empty Queue" << endl;
            return -1;
        }
        return queueArray[outQue];
    }
};