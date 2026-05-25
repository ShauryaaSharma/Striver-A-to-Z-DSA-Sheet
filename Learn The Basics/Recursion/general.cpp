#include<iostream>
using namespace std;

int function(int n){
    if(n > 0){
        cout << "The currnt value of n is: " << n << endl;
        function(n-1);
    }
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    function(n);
    return 0;
}