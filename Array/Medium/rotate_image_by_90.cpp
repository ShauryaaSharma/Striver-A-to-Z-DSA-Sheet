#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class Solution{
    public: 
    void bruteForce(int **A, int n){
        int ans[n][n];
        for(int i = 0; i< n; i ++){
            for(int j = 0; j < n; j ++){
                ans[j][n-1-i] = A[i][j];
            }
        }
    }

    void optimalApproch(int **A, int n){
        for(int i = 0; i < n-1; i ++){
            for(int j = i+1; j < n; j ++){
                swap(A[i][j], A[j][i]); 
            }
        }
        for(int i = 0; i < n; i ++){
            reverse(A[i], A[i] +n);
        }

    }
};

int main(){

    int n;

    cout << "Enter number of rows and columns: ";
    cin >> n;

    // Allocate memory for n rows
    int **A = new int *[n];

    // Allocate memory for m columns in each row
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
    }

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\nMatrix is:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    Solution s;
    s.optimalApproch(A, n);

    cout << "\n New Matrix is:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}