#include <iostream>
using namespace std;

class Solution {
public:

    int reverseNumber(int n) {

        int ld;
        int sum = 0;

        while(n > 0) {

            ld = n % 10;

            n = n / 10;

            sum = (sum * 10) + ld;
        }

        return sum;
    }
};

int main() {

    int n;

    cout << "Enter a number: ";
    cin >> n;

    Solution obj;

    int reversed = obj.reverseNumber(n);

    cout << "Reversed number: " << reversed << endl;

    return 0;
}