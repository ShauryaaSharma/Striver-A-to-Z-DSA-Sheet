#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution{
    private:
    bool linear_search(int *A, int n, int num){
        for(int i = 0; i < n; i ++){
            if(A[i] == num){
                return true;
            }
        }
        return false;
    }

    public:
    int bruteForce(int *A, int n){
        sort(A, A+n);
        int length = 1;
        int max_length = 1;
        for(int i = 1; i < n; i ++){
            if(A[i] == A[i-1] + 1){
                length ++;
            }else{
                length = 1;
            }
            max_length = max(max_length, length);
            
        }
        return max_length;
    }

    int better_bruteForce(int *A, int n){
        int longest = 1;
        for(int i = 0; i < n; i ++){
            int count = 1;
            while(linear_search(A, n, A[i]) == true){
                A[i]+1;
                count ++;
            }
            longest = max(longest, count);
        }
        return longest;
    }

    int better(int *A, int n){
        sort(A, A+n);
        int last_smaller = INT_MAX;
        int count = 0;
        int max_count = 1;
        for(int i = 0; i < n; i ++){
            if(A[i] - 1 == last_smaller){
                count++;
                last_smaller = A[i];
            }
            else if(A[i] != last_smaller){
                count = 1;
                last_smaller = A[i];
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }

    int optimalApproch(int *A, int n){
        int count = 0;
        int longest = 0;
        set<int> mySet;
        for(int i = 0; i < n; i ++){
            mySet.insert(A[i]);
        }
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

    Solution s;
    int result = s.bruteForce(A, n);

    cout << result;

    delete[] A;

    return 0;
}