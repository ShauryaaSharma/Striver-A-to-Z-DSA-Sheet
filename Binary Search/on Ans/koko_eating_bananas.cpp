#include <iostream>
#include<cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:
    int hoursUsed(vector<int> &A, int h, int val){
        int max_value = *max_element(A.begin(), A.end());
        int n = A.size();
        int count = 0; 
        int totalCount = 0;
        for(int j = 0; j < n; j++){
            count = ceil((A[j] + val - 1)/val);
            totalCount += count;
        }
        return totalCount;
    }
    

    public:
    int bruteForce(vector <int>&A, int h){
        int max_value = *max_element(A.begin(), A.end());
        int n = A.size();

        for(int i = 1; i <= max_value; i++){
            int count = 0; 
            int totalCount = 0;
            for(int j = 0; j < n; j++){
                count = ceil((A[j] + i - 1)/i);
                totalCount += count;
            }
            if(totalCount <= h){
                return i;
            }else{
                count = 0;
                totalCount = 0;
            }
        }
        return -1;
    }

    int optimalSearch(vector <int>&A, int h){
        int n = A.size();
        int low = *A.begin();
        int high = *A.end();
        while(low <= high){
            int mid = low + (high - low) / 2;
            int totalHours = hoursUsed(A, h, mid);
            if(totalHours <= h){
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
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

    int h;
    cout << "Enter the value of h: ";
    cin >> h;

    cout << endl;

    Solution s;
    int result = s.bruteForce(nums, h);
    cout << "The minimum number of banana is: " << result;


    return 0;
}