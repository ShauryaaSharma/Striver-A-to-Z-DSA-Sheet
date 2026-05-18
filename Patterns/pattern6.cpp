#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int n);
    void printPattern6();
};

Solution::Solution(int n){
    this -> n = n;
}

void Solution::printPattern6(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << j+1;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "The value of n is this pattern is: "; cin >> n;

    Solution s(n);
    s.printPattern6();
}