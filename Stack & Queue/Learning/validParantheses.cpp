#include <iostream>
#include <stack>
using namespace std;

class Solution{
    stack<char> st;

    public:
    bool ParaVal(string data){
        int stringLength = data.length();
        for(int i = 0; i < stringLength; i ++){
            if(data[i] == '{' || data[i] == '(' || data[i] == '['){
                st.push(data[i]);
            }else if(data[i] == '}' || data[i] == ')' || data[i] == ']'){
                if(!st.empty()){
                    int chari = st.top();
                    if(data[i] == '}' && chari == '{'){
                        st.pop();
                    }else if(data[i] == ')' && chari == '('){
                        st.pop();
                    }else if(data[i] == ']' && chari == '['){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string data;
    cout << "Enter string: ";
    cin >> data;

    if(sol.ParaVal(data))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}