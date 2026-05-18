#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern8();
};

Solution::Solution(int n){
    this -> n = n;
}

void Solution::printPattern8(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < (2*n) - (2*i+1); j++){
            cout << "*";
        }
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of n is this pattern is: "; cin >> n;

    Solution s(n);
    s.printPattern8();
}