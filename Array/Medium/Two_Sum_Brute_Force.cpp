#include <iostream>
using namespace std;

class Solution
{
private:
public:
    bool varient1(int *A, int n, int t)
    {
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum = A[i] + A[j];
                if (sum == t)
                {
                    return true;
                }
            }
        }
        return false;
    }

    pair<int, int> varient2(int *A, int n, int t){
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i+1; j < n; j++)
            {
                sum = A[i] + A[j];
                if (sum == t)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
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

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;
    pair<int, int> result = s.varient2(A, n, k);

    cout << "A Subarray with summation value of 2 is present: " << result.first << " " << result.second << endl;

    return 0;
}