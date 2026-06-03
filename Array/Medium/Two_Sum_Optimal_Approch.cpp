#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
private:
public:
    bool varient1(int *A, int n, int t)
    {
        int i = 0;
        int j = n-1;
        sort(A, A+n);
        while(i < j){
            if(A[i] + A[j] < t){
                i++;
            }
            if(A[i] + A[j] > t){
                j--;
            }
            if(A[i] + A[j] == t){
                return true;
            }
        }
        return false;
    }

    pair<int, int> varient2(int *A, int n, int t){
        int i = 0;
        int j = n-1;
        vector<pair<int, int>> numsWithIndex;
        for(int i = 0; i < n; i ++){
            numsWithIndex.push_back({A[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());
        while(i < j){
            if(numsWithIndex[i].first + numsWithIndex[j].first < t){
                i++;
            }
            else if(numsWithIndex[i].first + numsWithIndex[j].first > t){
                j--;
            }
            else if(numsWithIndex[i].first + numsWithIndex[j].first == t){
            return {numsWithIndex[i].second, numsWithIndex[j].second};
            }
        }
        return {-1, -1};
    }
};

int main()
{
    int n;
    cout << "Value of N: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter the value of the array: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> A[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution s;
    // bool result1 = s.varient1(A, n, k);
    pair<int, int> result2 = s.varient2(A, n, k);

    // cout << "A Subarray with summation value of 2 is present: " << result1 << endl;
    cout << "A Subarray with summation value of 2 is present: " << result2.first << " " << result2.second << endl;

    return 0;
}