#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern13();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern13(){
    int num = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
} 

int main(){
    int n;
    cout << "The value of n in this pattern is: "; cin >> n;
    Solution s(n);
    s.printPattern13();
}