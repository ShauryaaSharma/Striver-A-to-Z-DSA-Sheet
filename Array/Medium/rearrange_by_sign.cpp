#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n){
        vector<int> Positives;
        vector<int> Negatives;

        for(int i = 0; i < n; i++){
            if(A[i] >= 0){
                Positives.push_back(A[i]);
            }else{
                Negatives.push_back(A[i]);
            }
        }

        for(int i = 0; i < n/2; i++){
            A[2*i] = Positives[i];
            A[2*i+1] = Negatives[i];
        }
    }

    vector<int> optimalSolution(int *A, int n){
        vector<int> ans(n, 0);
        int postInx = 0;
        int negaInx = 1;

        for(int i = 0; i < n; i ++){
            if(A[i] > 0){
                ans[postInx] = A[i];
                postInx += 2;
            } else {
                ans[negaInx] = A[i];
                negaInx += 2;
            }
        }
        return ans;
    }
};

int main(){
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
    vector<int> result = s.optimalSolution(A, n);

    for (auto element:result)
    {
        cout << element << " ";
    }

    return 0;
}