#include <iostream>
using namespace std;

class Solution{
    private:
    int lowerBound(int *A, int n, int k){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            
            if(A[mid] >= k){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(int *A, int n, int k){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;

            if(A[mid] > k){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public:
    int bruteForce(int *A, int n, int k){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == k){
                count ++;
            }
        }
        return count;
    }

    int optimalApproch(int *A, int n, int k){
        int lb = lowerBound(A, n, k);
        int ub = upperBound(A, n, k);
        int result = ub - lb;
        return result; 
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