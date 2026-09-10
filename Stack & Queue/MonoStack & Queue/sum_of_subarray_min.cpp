#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMinsBrute(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i ++){
            int mini = arr[i];
            for(int j = i; j < n; j ++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
    }

    int sumSubarrayMinsOptimal(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9 + 7;
        stack<int> st;
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return sum;
    }
};