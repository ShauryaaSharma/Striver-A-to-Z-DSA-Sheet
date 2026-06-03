#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    void moveZero(int *A, int n){
        int j = -1;

        for(int i = 0; i < n; i++){
            if(A[i] == 0){
                j = i;
                break;
            } else {
                j=0;
            }
        }
        for(int i = j+1; i < n; i++){
            if(A[i] != 0 && A[j] == 0){
                swap(A[i], A[j]);
                j++;
            }
        }
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

    Solution s;
    s.moveZero(A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    return 0;
}