#include <iostream>
using namespace std;

class Solution{
    public:
    int optimalApproch(int *A, int n){
        int lastDuplicate = -1;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(A[i] == A[j] && A[i] != lastDuplicate){
                    cout << A[i] << endl;
                    lastDuplicate = A[i];
                }
            }
        }
    }
};

int main(){

    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int *A = new int[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter element: ";
        cin >> A[i];
    }

    class Solution s;
    s.optimalApproch(A, size);

    return 0;
}