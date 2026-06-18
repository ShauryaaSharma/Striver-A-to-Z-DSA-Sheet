#include <iostream>
using namespace std;

class Solution{
    // search a target from a sorted array assuming no duplicate numbers
    private:

    public:
    // int bruteForce(int *A, int n, int k){
    //     for(int i = 0; i < n; i ++){
    //         if(A[i] == k){
    //             return i;
    //         }
    //     }
    //     return -1;
    // } This wont be considered here bec it is linear search. 

    int bruteForce(int *A, int n, int k){
        int low = 0;
        int high = n-1;
        
        while(high >= low){
            int mid = (high + low)/2;
            if(k == mid){
                return A[mid];
            }
            else if(k < A[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }

    int recurssion(int *A, int n, int k, int low, int high){
        if(low > high){
            return -1;
        }
        int mid = (low + high)/2;
        if(k == A[mid]){
            return mid;
        }
        else if(k > A[mid]){
            return recurssion(A, n, k, mid + 1, high);
        }
        else {
            return recurssion(A, n, k, low, mid - 1);
        }
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
    int result = s.recurssion(A, n, k, 0, n-1);

    cout << "The value of index is: " << result;

    return 0;
}