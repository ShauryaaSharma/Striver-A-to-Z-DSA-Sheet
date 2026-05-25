#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern20();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern20(){
    for(int i = 0; i < n; i++){
        for(char ch = 'E' - i; ch <= 'E'; ch++){
            cout << ch;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of the patterns length: "; cin >> n;
    Solution p(n);
    p.printPattern20();
}