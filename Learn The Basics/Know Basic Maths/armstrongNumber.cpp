#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:

    int armstrongNumber(int n) {

        int original = n;
        int temp = n;

        int count = 0;

        while(temp > 0){
            count++;
            temp = temp / 10;
        }

        int ARM = 0;
        int ld;

        temp = n;

        while(temp > 0){

            ld = temp % 10;

            ARM = ARM + pow(ld, count);

            temp = temp / 10;
        }

        cout << "The value after summation " << ARM << endl;

        if(ARM == original){
            cout << original << " is an Armstrong Number";
        }
        else{
            cout << original << " is NOT an Armstrong Number";
        }

        return ARM;
    }
};

int main(){

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    obj.armstrongNumber(n);

    return 0;
}