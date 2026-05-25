#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern14();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern14(){
    for(int i = 0; i < n; i++){
        for(char c = 'A'; c <= 'A'+i; c++){
            cout << c << " ";
        }
        cout << endl;
    }
} 

int main(){
    int n;
    cout << "The value of n in this pattern is: "; cin >> n;
    Solution s(n);
    s.printPattern14();
}