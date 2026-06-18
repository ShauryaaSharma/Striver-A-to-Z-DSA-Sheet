#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n, int k){
        for(int i = 0; i < n; i ++){
            if(A[i] > k){
                return i;
            }
        }
        return n;
    }
    
    int optimalApproch(int *A, int n, int k){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low+high)/2;
            if(A[mid] > k){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
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
        cout << "Enter " << i << " value: ";
        cin >> A[i];
    }

    Solution s;
    int result = s.optimalApproch(A, n, k);

    cout << "The value of index is: " << result;

    return 0;
}