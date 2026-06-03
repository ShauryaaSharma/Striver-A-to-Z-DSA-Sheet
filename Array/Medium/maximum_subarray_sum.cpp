#include <iostream>
#include <climits>
using namespace std;

class Solution
{
private:
public:
    int bruteForce(int *A, int n)
    {
        int max_sum = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = 0;

                for (int k = i; k <= j; k++)
                {
                    sum += A[k];
                }
                max_sum = max(sum, max_sum);
            }
        }
        return max_sum;
    }

    int bruteForce(int *A, int n)
    {
        int max_sum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += A[j];
                max_sum = max(sum, max_sum);
            }
        }
        return max_sum;
    }

    int optimalApproch(int *A, int n ){
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < n; i ++){
            sum += A[i];
            max_sum = max(max_sum, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return max_sum;
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
    int result = s.bruteForce(A, n);

    cout << "The sum of largest subarray is: " << result;

    return 0;
}