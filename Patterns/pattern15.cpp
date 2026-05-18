#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern15();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern15(){
    for(int i = 0; i < n; i++){
        for(char j = 'A'; j <= 'A'+(n-i-1); j++){
            cout << j;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of the patterns length: "; cin >> n;
    Solution p(n);
    p.printPattern15();
}