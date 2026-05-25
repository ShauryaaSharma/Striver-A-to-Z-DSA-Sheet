#include <iostream>
using namespace std;

class Solution {
public:

    bool isPalindrome(int n) {

        int ld;
        int sum = 0;
        int original = n;

        while(n > 0) {

            ld = n % 10;

            n = n / 10;

            sum = (sum * 10) + ld;
        }

        if(sum == original) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    bool result = obj.isPalindrome(n);

    if(result) {
        cout << n << " is a Palindrome Number";
    }
    else {
        cout << n << " is NOT a Palindrome Number";
    }

    return 0;
}