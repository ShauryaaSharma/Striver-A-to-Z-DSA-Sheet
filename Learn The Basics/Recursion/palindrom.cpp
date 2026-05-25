#include <iostream>
using namespace std;

bool reverse(int i, string &s){
    if(i >= s.size()/2){
        return true;
    }else {
        if(s[i] != s[s.size() - i - 1]){
            return false;
        }
    }
    return reverse(i+1, s);
}

int main(){
    string s;
    cout << "Enter a string ";
    cin >> s;

    bool result = reverse(0, s);
    cout << result;
    return 0;
}