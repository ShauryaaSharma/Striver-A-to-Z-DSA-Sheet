#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern2();
};

Solution::Solution(int n){
    this-> n = n;
}

void Solution::printPattern2(){
    for(int i = 0; i< n; i++){
        for(int j = 0; j < i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The pattern should have the n value of: "; cin >> n;
    Solution p(n);
    p.printPattern2();
}