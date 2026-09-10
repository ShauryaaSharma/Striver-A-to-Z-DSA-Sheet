#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> arr;
        int n = nums.size();
        if(n == 1){
            arr.push_back(-1);
            return arr;
        }
        for(int i = 0; i < n; i ++){
            int counter = n;
            int j = i+1;
            while(counter > 0){
                if(j >= n){
                    j = j-n;
                }
                if(!st.empty() && nums[j] > nums[i]){
                    st.pop();
                    arr.push_back(nums[j]);
                    st.push(nums[j]);
                    break;
                }else if(!st.empty() && nums[j] <= nums[i]){
                    j++;
                    if(counter == 1){
                        arr.push_back(-1);
                        break;
                    }
                }else if(st.empty()){
                    st.push(nums[i]);
                }
                counter--;
            }
        }
        return arr;
    }
};