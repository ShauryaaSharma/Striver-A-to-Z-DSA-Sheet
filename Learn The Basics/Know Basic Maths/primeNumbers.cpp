#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int primeNumbers(int n) {
        int fac = 0;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                fac++;
                if((n/i) != i){
                    fac++;
                }
            }
        }
        return fac;
    }
};

int main(){

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    int result = obj.primeNumbers(n);

    if(result == 2){
        if(result = 1||n){
            cout << n << " is a prime number.";
        }
    }
    else{
        cout << n << " is NOT a prime number.";
    }

    return 0;
}