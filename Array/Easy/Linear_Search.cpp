#include <iostream>
using namespace std;

class Solution{
    private:

    public:
    int linearSearch(int *A, int n, int x){
        for(int i = 0; i < n; i++){
            if(A[i] == x){
                return i;
            }
        }
    }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5}; 
    int num = 3;  
     
    Solution s;
    int result = s.linearSearch(arr, 5, num);

    cout << result;
}
