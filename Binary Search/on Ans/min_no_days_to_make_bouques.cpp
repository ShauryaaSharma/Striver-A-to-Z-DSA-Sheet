#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    private:

    public:
    int bruteForce(vector<int>&nums, int m, int k){
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        for(int i = low; i <= high; i ++){
            int count = 0;
            int together = 0;
            for(int j = 0; j < n; j ++){
                if(i >= nums[j]){
                    count ++;
                    if(count == k){
                        together++;
                    }
                }else {
                    count = 0;
                }
            }
            if(together >= m){
                return i;
            }
        }
        return -1;
    }

    int optimalSolution(vector <int>&nums, int m, int k){
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        if(1LL * m * k > n){
            return -1;
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = 0;
            int together = 0;

            for(int j = 0; j < n; j ++){
                if(mid >= nums[j]){
                    count ++;
                    if(count == k){
                        together++;
                        count = 0;
                    }
                }else {
                    count = 0;
                }
            }
            if(together >= m){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (low > *max_element(nums.begin(), nums.end())) ? -1 : low;
    }
};

int main(){
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter " << i+1 << "th element: ";
        cin >> nums[i];
    }

    cout << endl;

    cout << "Vector elements are: ";
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    int m;
    cout << "Enter the value of m: ";
    cin >> m;

    cout << endl;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << endl;

    Solution s;
    int result = s.optimalSolution(nums, m, k);
    cout << "The minimum number of days is: " << result;


    return 0;
}