#include <iostream>
using namespace std;

class Solution{
    public:
    int optimalApproch(int *A, int n){
        if(n == 1){
            return 0;
        }else if(A[0] > A[1]){
            return A[0];
        }else if(A[n-1] > A[n-2]){
            return A[n-1];
        }

        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
                return A[mid];
            }else if(A[mid] > A[mid - 1]){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){

    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    int *A = new int[n];
    cout << "Start filling the array of size " << n << endl;
    for(int i = 0; i < n; i ++){
        cout << "Enter value of " << i << " index: ";
        cin >> A[i];
    }

    Solution s;
    int result = s.optimalApproch(A, n);

    cout << "The answer is: " << result;

    delete []A;

    return 0;
}