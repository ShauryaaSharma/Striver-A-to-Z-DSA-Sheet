#include <iostream>
using namespace std;

void function(int A[], int l, int r){
    if(l >= r){
        return;
    } else {
        int temp = A[l];
        A[l] = A[r];
        A[r] = temp;

        function(A, l+1, r-1);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    function(arr, 0, n-1);

    cout << "Reversed array: " << endl;
    for(int i = 0; i < n ; i++){
        cout << arr[i] << endl;
    }

    return 0;
}