#include <iostream>
using namespace std;

class Solution{
    private:
    

    public:
    int optimalApproch(int *A, int n, int k){
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(A[mid] == k){
                return mid;
            }

            if(A[low] <= A[mid]){
                if(A[low] <= k && k < A[mid]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            else {
                if(A[mid] < k && k <= A[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
    
};

int main(){

    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int *A = new int[n];
    cout << "Start filling the array of size " << n << endl;
    for(int i = 0; i < n; i ++){
        cout << "Enter value of " << i << " index: ";
        cin >> A[i];
    }

    Solution s;
    int result = s.optimalApproch(A, n, k);

    cout << "The answer is: " << result;

    delete []A;

    return 0;
}