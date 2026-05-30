#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int rotation(int *A, int n){
        int temp = A[0];
        for(int i = 0; i < n; i++){
            A[i] = A[i+1];
        }
        A[n-1] = temp;
        return 0;
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
    s.rotation(A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    return 0;
}