#include <iostream>
using namespace std;

class Solution{
    private: 
    int n;

    public:
    Solution(int n);
    void printPattern10();
};

Solution::Solution(int n){
    this->n = n;
}

void Solution::printPattern10(){
    for(int i = 0; i < n; i++){
        if(i<n){
            for(int j = 0; j < i+1; j++){
                cout << "*";
            }
            cout << endl;
        }         
    }
    for(int i = n; i < n+(n-1); i++){
        for(int j = 0; j < n-i+(n-1); j++){
            cout << "*";
        }
        cout << endl;
    }
} 

// OR

// void Solution::printPattern10(){

//     for(int i = 0; i < 2*n-1; i++){

//         int stars;

//         if(i < n){
//             stars = i + 1;      // Increasing part
//         }
//         else{
//             stars = 2*n - i - 1; // Decreasing part
//         }

//         for(int j = 0; j < stars; j++){
//             cout << "*";
//         }

//         cout << endl;
//     }
// }

int main(){
    int n;
    cout << "The value of n in this pattern is: "; cin >> n;
    Solution s(n);
    s.printPattern10();
}