#include <iostream>
using namespace std;

class LargestElement {
public:

    bool optimalApproch(int *A, int n) {

        for(int i = 0; i < n - 1; i++) {

            if(A[i] > A[i + 1]) {
                return false;
            }
        }

        return true;
    }

    bool bruteForce(int *A, int n){
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {
                if(A[i] > A[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

    int size;

    cout << "Enter size of array: ";
    cin >> size;

    int *A = new int[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter element: ";
        cin >> A[i];
    }

    LargestElement a;

    bool result = a.optimalApproch(A, size);

    if(result) {
        cout << "Array is sorted in ascending order" << endl;
    }
    else {
        cout << "Array is NOT sorted" << endl;
    }

    delete[] A;

    return 0;
}