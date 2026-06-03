#include <iostream>
#include <map>
using namespace std;

class Solution
{
private:
public:
    int betterApproch(int *A, int n)
    {
        int num0 = 0;
        int num1 = 0;
        int num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
            {
                num0++;
            }
            else if (A[i] == 1)
            {
                num1++;
            }
            else if (A[i] == 2)
            {
                num2++;
            }
        }
        cout << num0 << " " << num1 << " " << num2 << endl;
        int index = 0;
        while (num0 > 0)
        {
            A[index] = 0;
            num0--;
            index++;
        }
        while (num1 > 0)
        {
            A[index] = 1;
            num1--;
            index++;
        }
        while (num2 > 0)
        {
            A[index] = 2;
            num2--;
            index++;
        }
        return 0;
    }

    int betterApproch(int *A, int n)
    {
        map<int, int> myHash;
        for (int i = 0; i < n; i++)
        {
            myHash[A[i]]++;
        }
        for (auto element : myHash)
        {
            for (int i = 0; i < element.second; i++)
            {
                A[i] = element.first;
            }
        }
        return 0;
    }

    int bruteForce(int *A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[j] < A[i])
                {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
    }

    int DNF(int *A, int n){
        int low = 0; int mid = 0; int high = n-1;
        while(mid <= high){
            if(A[mid] == 0){
                swap(A[low], A[mid]);
                low++;
                mid++;
            }else if(A[mid] == 1){
                mid++;
            }else if(A[mid] == 2){
                swap(A[mid], A[high]);
                high--;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;

    int *A = new int[n];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> A[i];
    }

    Solution s;
    int result = s.bruteForce(A, n);

    cout << "The new sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}