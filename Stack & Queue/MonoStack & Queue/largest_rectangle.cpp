#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    vector<int> prevSmallerEle(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i ++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerEle(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i = n-1; i >= 0; i --){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = prevSmallerEle(heights);
        vector<int> nse = nextSmallerEle(heights);
        int biggest = INT_MIN;
        for(int i = 0; i < n; i ++){
            int area = heights[i] * (nse[i] - pse[i] - 1);
            biggest = max(biggest, area); 
        }
        return biggest;
    }
};