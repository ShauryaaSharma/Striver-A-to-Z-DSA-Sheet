#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n, int k){
        for(int i = 0; i < n; i ++){
            if(A[i] <= k){
                k++;
            }else{
                break;
            }
        }
        return k;      
    }
};

int main(){
    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    int *A = new int[n];
    cout << "Start filling the array of size " << n << endl;
    for(int i = 0; i < n; i ++){
        cout << "Enter value of " << i << " index: ";
        cin >> A[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;
    int result = s.bruteForce(A, n, k);

    cout << "The answer is: " << result << endl;

    delete []A;
    return 0;
}