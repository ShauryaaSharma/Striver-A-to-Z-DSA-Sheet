#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int optimalApproch(int n){

        int low = 0;
        int high = n-1;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low);

            if(mid*mid <= n){
                ans = mid;
                low = mid + 1;
            }else if(mid * mid > n){
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cout << "Value of N: ";
    cin >> n;

    Solution s;
    int result = s.optimalApproch(n);

    cout << "The value of index is: " << result;

    return 0;
}