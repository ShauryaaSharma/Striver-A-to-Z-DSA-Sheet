#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern5();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern5(){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of the patterns length: "; cin >> n;
    Solution p(n);
    p.printPattern5();
}