#include <iostream>
using namespace std;

class Solution {
public:

    int GCD(int n1, int n2) {
        int fac = 0;
        int select;

        if(n1 > n2){
            select = n2;
        } else {
            select = n1;
        }
        int largestNum = 0;
        for(int i = 1; i <= select; i++){
            if(select%i == 0){
                cout << "The factors of " << n1 << " " << n2 << ": " << i << endl;
                fac++;
                if(i > largestNum){
                    largestNum = i;
                }
            }
        }


        return largestNum;
    }

    // OR

    // int HCF(int n1, int n2){
    //     for(int i = min(n1, n2); i >= 1; i--){
    //         if(n1%i == 0 && n2%i == 0){
    //             cout << i;
    //             break;
    //         }
    //     }
    // }
};

int main() {

    int n1;
    int n2;

    cout << "Enter first number: ";
    cin >> n1;

    cout << "Enter second number: ";
    cin >> n2;

    Solution obj;

    int result = obj.GCD(n1, n2);
    cout << "The Largest Common Factor between " << n1 << " and " << n2 << " is: " << result;

    return 0;
}