#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern17();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern17(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
            cout << " ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1) / 2;
        for(int j = 1; j <=2*i +1; j++){
            cout << ch;
            if(j <= breakpoint){
                ch++;
            }else {
                ch--;
            }
        }
        for(int j; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of the patterns length: "; cin >> n;
    Solution p(n);
    p.printPattern17();
}