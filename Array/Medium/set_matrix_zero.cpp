#include <iostream>
using namespace std;
class Solution
{
private:
    void change_row(int **A, int m, int x)
    {
        for (int i = 0; i < m; i++)
        {
            if (A[x][i] != 0)
            {
                A[x][i] = -1;
            }
        }
    };
    void change_col(int **A, int n, int y)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[j][y] != 0)
            {
                A[j][y] = -1;
            }
        }
    };

public:
    int bruteForce(int **A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[i][j] == 0)
                {
                    change_row(A, m, i);
                    change_col(A, n, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[i][j] == -1)
                {
                    A[i][j] = 0;
                }
            }
        }
    }

    int betterSolution(int **A, int n, int m){
        int X[n] = {0};
        int Y[m] = {0};

        for(int i = 0; i < n; i ++){
            for(int j = 0; i < m; j++){
                if(A[i][j] == 0){
                    X[i] = 1;
                    X[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(X[i] == 1 || X[j] == 1){
                    A[i][j] = 0;
                }
            }
        }
    }
};       

int main()
{
    int n, m;

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    // Allocate memory for n rows
    int **A = new int *[n];

    // Allocate memory for m columns in each row
    for (int i = 0; i < n; i++)
    {
        A[i] = new int[m];
    }

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "\nMatrix is:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    Solution s;
    s.bruteForce(A, n, m);

    cout << "\n New Matrix is:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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