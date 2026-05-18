#include <iostream>
using namespace std;

class Solution{
    private:
    int n;

    public:
    Solution(int x){
        n = x;
    }

    void printPattern(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main(){
    cout << "The value of n in this patter is: ";
    int n; cin >> n;
    Solution s(n);
    s.printPattern();
}