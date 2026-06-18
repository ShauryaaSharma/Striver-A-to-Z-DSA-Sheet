#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(int *A, int n, int k){
        int count = 0;
        for(int i = 0; i < n; i ++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += A[j];
                if(sum == k){
                    count ++;
                }
            }
            sum = 0;
        }
        return count;
    }

    int optimalApproch(int *A, int n, int k){
        unordered_map<int, int> myMap;
        int sum = 0;
        int count = 0;

        for(int i = 0; i < n; i ++){
            sum += A[i];
            myMap[sum] = i;
            int remove = sum -k;
            if(myMap.find(remove) != myMap.end()){
                count += myMap[remove];
            }
            myMap[sum]++;
        }

        return count;
    }
};

int main(){
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
    int result = s.bruteForce(A, n, k);

    cout << "Number of sub-arrays is: " << result;

    return 0;
}