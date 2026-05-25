#include <iostream>
using namespace std;

class Solution
{
private:
    int n;

public:
    Solution(int n);
    void printPattern19();
};

Solution::Solution(int n)
{
    this->n = n;
}

void Solution::printPattern19()
{
    int iniS = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        iniS += 2;
        cout << endl;
    }
    iniS = 2 * n - 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < iniS; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= i + 1; j++)
        {
            cout << "*";
        }

        iniS -= 2;

        cout << endl;
    }
}

int main()
{
    int n;
    cout << "The value of the patterns length: ";
    cin >> n;
    Solution p(n);
    p.printPattern19();
}