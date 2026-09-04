#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
private: 
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i < n; i ++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int element = st.top();
                st.pop();
                int next = i;
                int prev;
                if(st.empty()){
                    prev = -1;
                }else{
                    prev = st.top();
                }
                maxArea = max(maxArea, heights[element] * (next - prev - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int next = n;
            int element = st.top();
            st.pop();
            int prev;
            if(st.empty()){
                prev = -1;
            }else{
                prev = st.top();
            }
            maxArea = max(maxArea, heights[element] * (next - prev - 1));
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxArea = 0;

        for(auto& row : matrix){
            for (int i = 0; i < m; i++) {
                if(row[i] == '1'){
                    height[i]++;
                }else{
                    height[i] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(height));
        }
        return maxArea;
    }
};