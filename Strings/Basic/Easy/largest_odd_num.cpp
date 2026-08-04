#include <iostream>
#include <string>
using namespace std;

class Solution{
    private:
    string reqCheck(string s){
        int n = s.size();
        if (s.empty() || s[0] != '0') {
            return s;
        }
        s.erase(0, 1);      
        return reqCheck(s);
    }
    public:
    string optimalApproch(string& s){
        
        string strCons =  reqCheck(s);

        int ind = -1;

        int i;
        for (i = s.length() - 1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }

        return s.substr(i, ind - i + 1);
    }
};

int main(){
    string word;
    cout << "Enter a single string: ";
    getline(cin, word);
    cout << "You had entered: " << word << endl;
    Solution sol;
    string result = sol.optimalApproch(word);
    cout << "You output is " << result << endl;
    return 0;
}