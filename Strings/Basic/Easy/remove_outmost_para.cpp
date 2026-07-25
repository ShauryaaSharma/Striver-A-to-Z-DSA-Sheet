#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    string bruteForce(string s){
        string temp = "";
        int depth = 0;

        for(char ch: s){
            if(ch == '('){
                if(depth > 0){
                    temp += ch;
                }
                depth ++;
            }else if(ch == ')'){
                depth --;
                if(depth > 0){
                    temp += ch;
                }
            }
        }
        return temp;
    }

    string optimalSolution(string s){
        int depth = 0;
        int write = -1;

        for(char ch: s){
            if(ch == '('){
                if(depth > 0){
                    s[write++] = ch;
                }
                depth ++;
            }else if(ch == ')'){
                depth --;
                if(depth > 0){
                    s[write++] = ch;
                }
            }
        }

        s.resize(write);
        return s;
    }
};

int main(){
    string word;
    cout << "Enter a single word: ";
    cin >> word; 
    cout << "You entered: " << word << endl;

    Solution sol;
    string result = sol.bruteForce(word);
    cout << "You output: " << result << endl;

    return 0;
}