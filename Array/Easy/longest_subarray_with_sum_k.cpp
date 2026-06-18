#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{

    public:
    int better(int *A, int n, int k){
        unordered_map<int, int> myHash;
        int sum = 0;
        int len = 0;
        int max_length = 0; 
        for(int i = 0; i < n; i ++){
            sum += A[i];
            if(sum == k){
                max_length = max(max_length, len);
            }
            int rem = sum - k;
            if(myHash.find(rem) != myHash.end()){
                int len = i - myHash[rem];
                max_length = max(max_length, len);
            }
            if(myHash.find(sum) == myHash.end()){
                myHash[sum] = i;
            }
        }
        return max_length; 
    }

    int optimal(int *A, int n, int k){
        int left = 0; 
        int right = 0;

        int sum = A[0];
        int max_length = 0;
        while(right < n){
            while(left <= right && sum > k){
                sum -= A[left];
                left++;
            }
            if(sum == k){
                max_length = max(max_length, right - left - 1);
            }
            right ++;
            if(right < n){
                sum += A[right];
            }
        }
        return max_length;
    }
};