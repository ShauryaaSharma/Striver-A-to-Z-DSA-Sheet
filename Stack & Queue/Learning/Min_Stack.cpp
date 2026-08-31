#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    public:
        
    stack<pair<int, int>> st;
        
    int smallest = INT_MAX;

    void push(int value) {
        if(smallest > value){
            smallest = value;
            st.push({value, smallest});
        }else{
            st.push({value, smallest});
        }
    }
    
    void pop() {
        st.pop();
        if(!st.empty()){
            smallest = st.top().second;
        }else if(st.empty()){
            smallest = INT_MAX;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};