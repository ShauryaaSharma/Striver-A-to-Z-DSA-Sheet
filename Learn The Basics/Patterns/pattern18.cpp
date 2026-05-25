#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern18();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern18(){
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
    p.printPattern18();
}