#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    bool linear_search(int *A, int n, int num)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] == num)
            {
                return true;
            }
        }
        return false;
    }

public:
    int Approch_1(int *A, int n)
    {
        sort(A, A + n);
        int count = 1;
        int max_count = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] != A[i + 1])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (A[i] + 1 == A[j])
                    {
                        count++;
                        break;
                    }
                    else
                    {
                        count = 1;
                    }
                }
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }

    int Approch_2(int *A, int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int max_count = 1;
        for (int i = 0; i < n; i++)
        {
            int x = A[i];
            int count = 1;
            while (linear_search(A, n, x + 1) == true)
            {
                x += 1;
                count += 1;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }

    int Approch_3(int *A, int n)
    {
        int lastSmaller = INT_MIN;
        int count = 0;
        int max_count = 1;

        for (int i = 0; i < n; i++)
        {
            if (A[i] - 1 == lastSmaller)
            {
                count += 1;
                lastSmaller = A[i];
            }
            else if (A[i] - 1 != lastSmaller)
            {
                count = 1;
                lastSmaller = A[i];
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }

    int Approch_4(int *A, int n){
        unordered_set<int> mySet;
        if(n == 0){
            return 0;
        }

        int max_count = 0;

        for(int i = 0; i < n; i ++){
            mySet.insert(A[i]);
        }

        for( auto element: mySet){
            if(mySet.find(element - 1) == mySet.end()){
                int count = 1;
                int x = element;
                while(mySet.find(x + 1) != mySet.end()){
                    count += 1;
                    x += 1;
                }
                max_count = max(max_count, count);
            }
        }
        return max_count;
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
    int result = s.Approch_4(A, n);

    cout << result;

    delete[] A;

    return 0;
}