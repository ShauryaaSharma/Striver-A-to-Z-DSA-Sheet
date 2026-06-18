#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int lowerBound(vector<int> arr, int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int> arr, int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int ans = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    int bruteForce(int *A, int n, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] > k)
            {
                return i - 1;
            }
        }
        return -1;
    }

    pair<int, int> optimalApproch(vector<int> arr, int n, int k)
    {
        int lb = lowerBound(arr, n, k);
        if(lb == n || arr[lb] != k){
            return {-1, -1};
        }

        return {lb, upperBound(arr, n, k) - 1};
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;

    int k;
    cout << "Value of K: ";
    cin >> k;

    int *A = new int[n];
    cout << "Enter the value of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: " << endl;
        cin >> A[i];
    }

    Solution s;
    int result = s.bruteForce(A, n, k);

    cout << "The value of index is: " << result;

    return 0;
}