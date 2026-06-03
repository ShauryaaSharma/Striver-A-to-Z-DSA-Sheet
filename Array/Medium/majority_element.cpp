#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
private:
public:
    int bruteForce(int *A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                if (A[j] == A[i])
                {
                    cnt++;
                }
            }

            if (cnt > n / 2)
                return A[i];
        }
    }

    int betterApproch(int *A, int n)
    {
        sort(A, A + n);

        int count = 1;
        int maxCount = 1;
        int majority = A[0];

        for (int i = 1; i < n; i++)
        {
            if (A[i] == A[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > maxCount)
            {
                maxCount = count;
                majority = A[i];
            }
        }

        if (maxCount > n / 2)
            return majority;

        return -1;
    }

    int evenBetterApproch(int *A, int n)
    {
        map<int, int> myHash;
        for (int i = 0; i < n; i++)
        {
            myHash[A[i]]++;
        }
        for (auto element : myHash)
        {
            if (element.second >= n / 2)
            {
                return element.first;
            }
        }
    }

    int optimalApproch(int *A, int n)
    {
        int cnt = 0;
        int el;

        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                el = A[i];
            }
            else if (el == A[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
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

    cout << "The number with the majority is: " << result;
}