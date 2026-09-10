#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> nextGreaterMap;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            if(st.empty()){
                nextGreaterMap[nums2[i]] = -1;
            }else{
                nextGreaterMap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x : nums1){
            ans.push_back(nextGreaterMap[x]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution sol;
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}