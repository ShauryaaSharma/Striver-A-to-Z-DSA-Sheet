#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(vector<int>& nums, int k){
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            if(nums[i] == k){
                return i;
            }
            else if(nums[i] > k){
                nums.insert(nums.begin() + i, k);
                return i;
            }
        }
        return 0;
    }

    int optimalApproch(vector<int>& nums, int k){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == k){
                return mid;
            }
            else if(nums[mid] < k){
                low = mid + 1;
            } else if(nums[mid] > k){
                ans = mid;
                high = mid - 1;
            }
        }

        nums.insert(nums.begin() + ans, k);
        return ans;
    }
};

int main(){
    int n;
    cout << "Enter the number of elemets: ";
    cin >> n;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<int> myVector;

    cout << "Enter " << n << " numbers " << endl;
    for(int i = 0; i < n; i ++){
        int input;
        cin >> input;

        myVector.push_back(input);
    }

    Solution s;
    int result = s.optimalApproch(myVector, k);

    for(int i = 0; i < myVector.size(); i ++){
        cout << myVector[i] << " ";
    }

    cout << endl;

    cout << result;

    return 0;
}