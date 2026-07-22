#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n, int limit){
        int maxi = *max_element(A, A+n);
        for(int i = 1; i <= maxi; i ++){
            int sum = 0;
            for(int j = 0; j < n; j ++){
                int r = ceil((double)A[j]/(double)i);
                sum += r;
            }
            if(sum <= limit){
                return i;
            }
        }
    }

    int optimalApproch(int *A, int n, int limit){
        int maxi = *max_element(A, A+n);
        if (n > limit) return -1;
        int low = 1;
        int high = maxi;
        int ans = INT_MAX;
        while(low <= high){
            int sum = 0;
            int mid = low + (high - low) / 2;
            for(int j = 0; j < n; j ++){
                int r = ceil((double)A[j]/(double)mid);
                sum += r;
            }
            if(sum <= limit){
                ans = min(ans, mid);
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
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

    int limit;
    cout << "Enter the value of limit: ";
    cin >> limit;

    Solution s;
    int result = s.optimalApproch(A, n, limit);

    cout << "The answer is: " << result;

    delete []A;
    return 0;
}