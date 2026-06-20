#include <iostream>
#include <climits>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n){
        int smallest = INT_MAX;
        int index = 0;
        for(int i = 0; i < n; i ++){
            if(A[i] < smallest){
                smallest = A[i];
                index = i;
            }
        }
        return index;
    }

    int betterApproch(int *A, int n){
        int index;
        for(int i = 0; i < n-1; i ++){
            if(A[i] > A[i+1]){
                index = i+1;
            }
        }
        return index;
    }

    int optimalApproch(int *A, int n){
        int low = 0;
        int high = n - 1;

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
    int result = s.bruteForce(A, n);

    cout << "The answer is: " << result;

    delete []A;

    return 0;
}