#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;

class Solution{
    private:
    int sum(vector<int>& arr){
        int total_sum = 0;
        for(const auto& x : arr){
            total_sum += x;
        }
        return total_sum;
    }

    public:
    int optimalSolution(vector<int>& arr, int m){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = arr[0];
        int high = sum(arr);
        int ans = 0;
        if (m > n){
            return -1;
        }

        while(low <= high){
            int mid = (high + low)/2;
            int stu = 1;
            int count = 0;
            for(int i = 0; i < n; i ++){
                if(arr[i] + count <= mid){
                    count += arr[i];
                }else{
                    count = 0;
                    count = arr[i];
                    stu++;
                }
            }
            if(stu > m){
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

    int m;
    cout << "Enter the value of k: ";
    cin >> m;

    Solution sol;
    int result = sol.optimalSolution(vec, m);
    cout << "The ans is: " << result << "\n";

    return 0;
}