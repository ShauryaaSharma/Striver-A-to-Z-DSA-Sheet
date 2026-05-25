#include <iostream>
using namespace std;

int function(int n){
    if(n>0){
        cout << "value of N: " << n << endl;
        return n + function(n-1);
        cout << "value of N: " << n << endl;
    }
}

int main(){

    int n;
    cout << "Value of N: " << endl;
    cin >> n;
    int result = function(n);
    cout << "The result is: " << result << endl; 

    return 0;
}