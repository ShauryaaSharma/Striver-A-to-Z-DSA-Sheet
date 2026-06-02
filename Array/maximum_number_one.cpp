#include <iostream>
using namespace std;

class Solution
{
private:
public:
    int maxOneCalculate(int *A, int n)
    {
        int maxValue = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }

            maxValue = max(maxValue, count);
        }
        return maxValue;
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> A[i];
    }

    Solution s;
    int result = s.maxOneCalculate(A, n);
    cout << "The value of the max consecutive number of one is: " << result << endl;

    return 0;
}