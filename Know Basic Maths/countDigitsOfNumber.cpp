#include <iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {

        // Special case for 0
        if(n == 0) {
            return 1;
        }

        int count = 0;

        while(n > 0) {
            int lastDig = n % 10;

            cout << "Current last digit: " << lastDig << endl;

            n = n / 10;
            count++;
        }

        return count;
    }

    // int countDigit(int n) {

    // // Special case for 0
    // if(n == 0)
    //     return 1;

    // int cnt = (int)(log10(n) + 1);

    // return cnt;
};


int main() {

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    int result = obj.countDigit(n);

    cout << "Total number of digits: " << result << endl;

    return 0;
}