#include <iostream>
using namespace std;

class Solution
{
private:
public:
    int bruteForce(int *A, int n, int k)
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] >= k)
            {
                return i;
            }
        }
    }

    int optimalApproch(int *A, int n, int k){
        int low = 0;
        int high = n-1;
        int l = 0;
        int h = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(A[mid] == k){
                return mid;
            }else if(A[mid] < k){
                l = mid;
                low = mid + 1;
            } else if(A[mid] > k){
                h = mid;
                high = mid - 1;
            }
        }
        //somehow return l and h, we can also write 2 seperate function.
    }
};

int main(){
    int n;
    cout << "Value of N: ";
    cin >> n;

    int k;
    cout << "Value of K: ";
    cin >> k;

    int *A = new int[n];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: " << endl;
        cin >> A[i];
    }

    Solution s;
    int result = s.bruteForce(A, n, k);

    cout << "The value of higher index is: " << A[result] << endl;
    cout << "The value of lower index is: " << A[result - 1];

    return 0;
}