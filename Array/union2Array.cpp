#include <iostream>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Solution
{
private:
public:
    map<int, int> myHash2;
    set<int> myHash;
    vector<int> myVec;

    void unionArray(int *A, int *B, int n)
    {

        for (int i = 0; i < n; i++)
        {
            myHash.insert(A[i]);
            myHash.insert(B[i]);
        }
    }

    void Map(int *A, int *B, int n)
    {

        for (int i = 0; i < n; i++)
        {
            myHash2[A[i]]++;
            myHash2[B[i]]++;
        }
    }

    void twoPointer(int *A, int *B, int n)
    {
        int i = 0;
        int j = 0;

        while (i < n && j < n)
        {
            if (A[i] < B[j])
            {
                if (myVec.empty() || myVec.back() != A[i])
                    myVec.push_back(A[i]);
                i++;
            }
            else if (B[j] < A[i])
            {
                if (myVec.empty() || myVec.back() != B[j])
                    myVec.push_back(B[j]);
                j++;
            }
            else
            {
                if (myVec.empty() || myVec.back() != A[i])
                    myVec.push_back(A[i]);
                i++;
                j++;
            }
        }

        while (i < n)
        {
            if (myVec.empty() || myVec.back() != A[i])
                myVec.push_back(A[i]);
            i++;
        }

        while (j < n)
        {
            if (myVec.empty() || myVec.back() != B[j])
                myVec.push_back(B[j]);
            j++;
        }
    }
};

int main()
{
    int *A = new int[5]{1, 2, 3, 4, 5};
    int *B = new int[5]{6, 7, 8, 9, 10};

    Solution s;
    s.twoPointer(A, B, 5);
    for (auto element : s.myVec)
    {
        cout << element << endl;
    }

    return 0;
}