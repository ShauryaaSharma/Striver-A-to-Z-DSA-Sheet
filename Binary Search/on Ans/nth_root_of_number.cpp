#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
private:
public:
    int bruteForce(int n, int m)
    {
        for (int i = 1; i <= m; i++)
        {
            int pr = pow(i, n);
            cout << "The power value: " << pr << endl;
            if (pr == m)
            {
                return i;
            }
        }
        return -1;
    }

    int optimalApproch(int n, int m)
    {
        int low = 1;
        int high =  m;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int pr = pow(mid, n);
            if (pr == m)
            {
                return mid;
            }
            else if (pr > m)
            {
                high = mid - 1;
            }
            else if (pr < m)
            {
                low = low + 1;
            }
        }

        return -1;
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;

    int m;
    cout << "Value of M: ";
    cin >> m;

    Solution s;
    int result = s.optimalApproch(n, m);

    cout << "The value of index is: " << result;

    return 0;
}