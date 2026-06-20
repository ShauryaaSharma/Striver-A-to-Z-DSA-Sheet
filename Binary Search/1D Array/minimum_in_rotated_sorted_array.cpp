#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int optimalApproch(int *A, int n){
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = low + (high - low) / 2;

            if(A[mid] > A[high]){
                low = mid + 1;

            }else {
                high = mid;
            }
        }

        return low;
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