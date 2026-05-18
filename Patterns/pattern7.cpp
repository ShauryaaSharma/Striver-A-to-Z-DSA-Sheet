#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern7();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern7(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        for(int j = 0; j < (2*i+1); j++){
            cout << "*";
        }
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of n for this pattern: "; cin >> n;

    Solution s(n);
    s.printPattern7();
}