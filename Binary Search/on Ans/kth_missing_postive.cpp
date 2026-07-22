#include <iostream>
#include <vector>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(vector<int> vec, int k){
        int n = vec.size();
        for(int i = 0; i < n; i ++){
            if(vec[i] <= k){
                k++;
            }else{
                break;
            }
        }
        return k;
    }

    int optimalSolution(vector<int> vec, int k){
        int n = vec.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            int missing = vec[mid] - (mid+1);

            if(missing < k){
                low = mid +1;
            }else{
                high = mid -1 ;
            }
        }

        return k+high+1;
    }
};

int main(){
    int size;
    cout << "Write the input for the size of the vector: ";
    cin >> size;

    vector<int> numbers;
    cout << "enter" << size << "numbers: \n";
    for(int i = 0; i < size; i ++){
        int temporary_input;
        cin >> temporary_input;
        numbers.push_back(temporary_input);
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;

    int result = sol.optimalSolution(numbers, k);
    cout << "The result is: " << result;
    return 0;
}