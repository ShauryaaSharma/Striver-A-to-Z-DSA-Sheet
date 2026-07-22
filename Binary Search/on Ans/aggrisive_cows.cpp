#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    private:
    bool canWePlace(int *A, int n, int cows, int d){
        int count = 1;
        int lastPos = A[0];

        for(int i = 1; i < n; i ++){
            if(A[i] - lastPos >= d){
                count ++;
                lastPos = A[i];
            }
            if(count >= cows){
                return true;
            }
        }
        return false;
    }

    public:
    int bruteForce(int *A, int n, int cows){
        sort(A, A+n);
        int maxDis = A[n-1] - A[0];
        
        int ans = 0;

        for(int i = 1; i < maxDis; i++){
            if(canWePlace(A, n, cows, i)){
                ans = i;
            }
        }
        return ans;
    }

    int optimalApproch(int *A, int n, int cows){
        sort(A, A+n);
        int low = A[0];
        int high = A[n-1] - A[0];
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(canWePlace(A, n, cows, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
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