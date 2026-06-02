#include <iostream>
#include <map>
using namespace std;

class Solution
{
private:
public:
    int maxOneCalculate(int *A, int n)
    {
        map<int, int> myMap;
        for(int i = 0; i < n; i++){
            myMap[A[i]]++;
        }
        for(auto element:myMap){
            if(element.first == 1){
                return element.first;
            }
        }
    }

    int XORApproch(int * A, int n){
        int xorr = 0;
        for(int i = 0; i< n; i++){
            xorr = xorr ^ A[i];
        }
        return xorr;
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
    int result = s.maxOneCalculate(A, n);
    cout << "The number which appears once is: " << result << endl;

    return 0;
}