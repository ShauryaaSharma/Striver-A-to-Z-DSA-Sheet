#include <iostream>
#include <stack>
using namespace std;

class StackQueue{
    stack<int> st1;
    stack<int> st2;
    
    public:
    void push(int data){
        st1.push(data);
    }

    int pop(){
        int sizeSt1 = st1.size();
        int sizeSt2 = st2.size();

        if(isEmpty()) throw runtime_error("Queue is empty");
        if(sizeSt2 <= 0){
            for(int i = 0; i < sizeSt1; i++){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int popped = st2.top();
        st2.pop();
        return popped;
        
    }

    int top(){
        int sizeSt1 = st1.size();
        int sizeSt2 = st2.size();
        
        if(isEmpty()) throw runtime_error("Queue is empty");
        if(sizeSt2 <= 0){
            for(int i = 0; i < sizeSt1; i++){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
};