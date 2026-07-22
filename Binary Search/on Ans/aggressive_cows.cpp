#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:
    bool presentOrNot(vector<int>& arr, int k, int x){
        int size = arr.size();
        int cow_count = k;
        int count = x;
        int i = 1; 
        int last_cow = 0;
        cow_count --;
        for(i; i < size; i ++){
            if(arr[i] - arr[last_cow] >= count){
                cow_count --;
                last_cow = i;
                if(cow_count == 0){
                    return true;
            }
            }
        }
        return false;
    }
    public:
    int bruteForce(vector<int>& arr, int k){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 1;
        int max_distance = arr[n-1] - arr[0];
        int ans = 0;
        for(count; count <= max_distance;  count++){
            if(presentOrNot(arr, k, count)){
                ans = count;
            }
        }
        return ans;
    }

    int optimalSolution(vector<int>& arr, int k){
        int n = arr.size();
        int low = 1; 
        int high = arr[n-1] - arr[0]; 
        int ans = 0;
        while(low <= high){
            int mid = (high + low)/2;
            if(presentOrNot(arr, k, mid)){
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