#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;

class LargestElement{
    public:
    int largest = 0;
    int optimalFun(int *A, int n){
        for(int i = 0; i < n; i++){
            if(A[i] > largest){
                largest = A[i];
            }
        }
        return largest;
    }

    int bruteForce(int *A, int n){
        sort(A, A+n);
        return A[n-1];
    }
};

int main(){
    int size;
    cout << "The size of the array: ";
    cin >> size;
    int *A;
    A = new int[size];
    for(int i = 0; i < size; i++){
        int val;
        cout << "Next of array: " << endl;
        cin >> val;
        A[i] = val;
    }
    
    LargestElement a;
    int optimalresult = a.optimalFun(A, size);
    cout << "The largest number of the array is: " << optimalresult << endl;

    int bruteForceResult = a.bruteForce(A, size);
    cout << "The largest number of the array is: " << bruteForceResult << endl;

    delete[] A;

    return 0;

}