#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:

    public:
    void brute_force(int *A, int n, int k) {
        int temp = A[n-1];
        if(k > 0){
            for(int i = n-2; i >= 0 ; i --){
                A[i+1] = A[i];
            }
            A[0] = temp;
            brute_force(A, n, k-1);
        }
    }

    void optimalApproch(int *A, int n, int k){

        k = k % n;  

        reverse(A, A+n);
        reverse(A, A + k);
        reverse(A + k, A + n);
    }
};

int main(){
    int n;
    cout << "The length of the array: ";
    cin >> n;
    int *A = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Element of array: ";
        cin >> A[i];
    }

    int k;
    cout << "Amount of Rotations: " ;
    cin >> k;

    Solution s;
    s.optimalApproch(A, n, k);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
}