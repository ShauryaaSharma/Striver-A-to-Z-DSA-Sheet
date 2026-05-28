#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class LargestElement{
    public:
    int bruteForce(int *A, int n){
        sort(A, A+n);
        cout << "The second smallest number is: " << A[1] << endl;
        cout << "The second largest number is: " << A[n-2] << endl;
        return 0;
    }

    int optimalApproch(int *A, int n){
        int min = INT_MAX;
        int mini = INT_MAX;
        int max = INT_MIN;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){         
            if(A[i] > max){
                maxi = max;
                max = A[i];
            }else if(A[i] > maxi && A[i] != max){
                maxi = A[i];
            }
            if(A[i] < min){
                mini = min;
                min = A[i];
            }else if (A[i] < mini && A[i] != min){
                mini = A[i];
            }
        }
        cout << "The second smallest number is: " << mini << endl;
        cout << "The second largest number is: " << maxi << endl;
        return 0;
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
    // int optimalresult = a.optimalFun(A, size);
    // cout << "The largest number of the array is: " << optimalresult << endl;

    int bruteForceResult = a.bruteForce(A, size);
    int betterApprochResult = a.optimalApproch(A, size);

    delete[] A;

    return 0;

}