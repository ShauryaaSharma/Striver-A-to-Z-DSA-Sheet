#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern11();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern11(){
    
    for(int i = 0; i < n; i++){
        int start;
        if(i % 2 == 0){
            start = 1;
        }else {
            start = 0;
        }
        for(int j = 0; j < i+1; j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
} 

int main(){
    int n;
    cout << "The value of n in this pattern is: "; cin >> n;
    Solution s(n);
    s.printPattern11();
}