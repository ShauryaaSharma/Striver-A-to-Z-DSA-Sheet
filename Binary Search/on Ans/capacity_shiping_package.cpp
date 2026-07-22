#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
    private:
    int sum_array(int *A, int n){
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += A[i];
        }
        return sum;
    }

    int concept(int *A, int n, int mid){
        int day = 1; 
        int load = 0;

        for(int i = 0; i < n; i ++){
            if(load + A[i] <= mid){
                load += A[i];
            }else {
                day ++;
                load = A[i];
            }
        }
        return day;
    }

    public:
    int bruteForce(int *A, int n, int d){
        int low = *max_element(A, A+n);
        int high = sum_array(A, n);

        for(int i = low; i <= high; i ++){
            int day = 1;
            int load = 0;
            for(int j = 0; j < n; j ++){
                if(load + A[j] <= i){
                    load += A[j];
                }else {
                    day++;
                    load = A[j];
                }
            }

            if(day <= d){
                return i;
            }
        }
        return -1;
    }

    int optimalApproch(int *A, int n, int d){
        int low = *max_element(A, A+n);
        int high = sum_array(A, n);

        while(low <= high){
            int mid = low + (high - low)/2;

            int days = concept(A, n, mid);

            if(days <= d){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    int n;
    cout << "Enter the value of n: " ;
    cin >> n;

    int *A = new int[n];
    cout << "Start filling the array of size " << n << endl;
    for(int i = 0; i < n; i ++){
        cout << "Enter value of " << i << " index: ";
        cin >> A[i];
    }

    int d;
    cout << "Enter the value of d: ";
    cin >> d;

    Solution s;
    int result = s.optimalApproch(A, n, d);

    cout << "The answer is: " << result << endl;

    delete []A;
    return 0;
}