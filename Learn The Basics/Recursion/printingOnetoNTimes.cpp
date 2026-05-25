#include <iostream>
using namespace std;

int function(int x, int n){
    if(x <= n){
        cout << "The current number is: " << x << endl;
        x++;
        function(x, n);
    }
    return x;
}

int main(){
    int x;
    cout << "Enter a starting number: ";
    cin >> x;

    int n;
    cout << "Enter an ending number: ";
    cin >> n;

    function(x, n);

    return 0;
}