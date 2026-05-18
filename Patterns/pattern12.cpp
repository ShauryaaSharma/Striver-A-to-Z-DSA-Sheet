#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern12();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern12(){
    for(int x = 0; x < n; x++){
        for(int i = 0; i < x+1; i++){
            cout << i+1;
        }
        for(int j = 0; j < ((2*n)-((x+1)*2)); j++){
            cout << " ";
        }
        for(int k = x+1; k >= 1; k--){
            cout << k;
        }
        cout << endl;

    }
} 

int main(){
    int n;
    cout << "The value of n in this pattern is: "; cin >> n;
    Solution s(n);
    s.printPattern12();
}