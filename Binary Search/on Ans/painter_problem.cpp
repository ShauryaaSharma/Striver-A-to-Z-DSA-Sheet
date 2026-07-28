#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:
    int arrSum(vector<int>& arr){
        int n = arr.size();
        int tempSum = 0;
        for(const auto& x: arr){
            tempSum += x;
        }
        return tempSum;
    }

    public:
    int optimalSolution(vector<int>& arr, int k){
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = arrSum(arr);
        int ans = 0;

        while(low <= high){
            int mid = (high + low)/2;
            int count = 0;
            int painterCount = 1;
            for(int i = 0; i < n; i ++){
                if(count + arr[i] <= mid){
                    count += arr[i];
                }else{
                    count = arr[i];
                    painterCount ++;
                } 
            }
            if(painterCount > k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }

        }

        return ans;
    }
};

int main(){
    int size;
    cout << "Enter the size of the array you want: ";
    cin >> size;

    vector<int> vec;
    cout << "Enter the value of "<< size << " numbers: ";
    for(int i = 0; i < size; i ++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.optimalSolution(vec, k);
    cout << "The ans is: " << result << "\n";

    return 0;
}