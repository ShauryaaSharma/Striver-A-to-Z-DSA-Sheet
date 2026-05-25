#include <iostream>
using namespace std;

class Solution {
public:

    int gcd(int a, int b) {

        while(a > 0 && b > 0) {

            if(a > b) {
                a = a % b;
            }
            else {
                b = b % a;
            }
        }

        if(a == 0) {
            return b;
        }
        else {
            return a;
        }
    }
};

int main() {

    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Solution obj;

    int ans = obj.gcd(a, b);

    cout << "GCD is: " << ans;

    return 0;
}