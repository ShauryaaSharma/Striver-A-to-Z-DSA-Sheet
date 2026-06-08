#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
public:
    vector<int> optimalApproch(int *A, int n)
    {
        int lastLeader = n - 1; // since always
        int search = lastLeader - 1;
        vector<int> ans = {A[lastLeader]};
        while (search >= 0)
        {

            if (A[search] > A[lastLeader])
            {
                lastLeader = search;
                ans.push_back(A[lastLeader]);
            }
            search--;
        }
        return ans;
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
    vector<int> result = s.optimalApproch(A, n);

    for (auto element : result)
    {
        cout << element << " ";
    }

    return 0;
}