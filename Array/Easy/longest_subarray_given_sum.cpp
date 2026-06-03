#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n, int a){
        int maxLength = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum = sum + A[k];
                }
                if(sum == a){
                    maxLength = max(maxLength, j-i+1);
                }
            }
        }
        return maxLength;
    }

    int optimalApproch(int *A, int n, int a){
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxLength = 0;
        while(right<n){
            while(left<=right && sum > a){
                sum = sum - A[left];
                left++;
            }
            if(sum == a){
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
            if(right < a){
                sum = sum + A[right];
            }
        }
        return maxLength;
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

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;
    int result = s.bruteForce(A, n, k);

    cout << "The longest subarray is: " << result << endl;


    return 0;
}