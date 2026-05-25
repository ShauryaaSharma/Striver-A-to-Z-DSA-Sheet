#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:

    // int printAllDivisor(int n) {
    //     for(int i = 1; i <= n; i++){
    //         if(n%i == 0){
    //             cout << "Divisor of n is: " << i << endl;
    //         }
    //     }
    //     return 0;
    // }

    int printAllDivisor(int n) {
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                cout << "Divisor of n is: " << i << endl;
                if((n/i) != i){
                    cout << "Divisor of n is: " << n/i << endl;
                }
            }
        }
        return 0;
    }
};

int main(){

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    obj.printAllDivisor(n);

    return 0;
}