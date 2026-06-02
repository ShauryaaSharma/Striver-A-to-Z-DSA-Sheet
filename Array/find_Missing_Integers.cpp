#include <iostream>
#include <map>

using namespace std;
class Solution
{

public:

    int missingNumber(int *A, int n)
    {
        map<int, int> myHash;
        for (int i = 0; i < n; i++)
        {
            myHash[A[i]]++;
        }
        for(int i = 1; i < n ; i++){
            if(myHash[i] == 0){
                cout << i << endl;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;
    // All elements should be distinct and should be b.w the range of 1-n
    int *A = new int[n];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> A[i];
    }

    Solution s;
    s.missingNumber(A, n);



    return 0;
}