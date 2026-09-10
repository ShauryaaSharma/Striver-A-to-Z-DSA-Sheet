#include <iostream>
#include <queue>
using namespace std;

class QueueStack{
    queue<int> q;

    public:

    void push(int data){
        int s = q.size();
        q.push(data);

        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int n = q.front();
        q.pop();
        return n;
    }

    int top(){
        return q.front();
    }

    bool isEmpty(){
        return q.empty();
    }
};