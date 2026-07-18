#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    private:

    public:
    int bruteForce(vector<int> arr1, vector<int> arr2){
    vector<int> arr3;
    int n = arr1.size();
    int m = arr2.size();

    int i = 0;
    int j = 0;

    while( i < n && j < m){
        if(arr1[i] < arr2[j]){
            arr3.push_back(arr1[i++]);
        }else{
            arr3.push_back(arr2[j++]);
        }
    }
    while(i < n){
        arr3.push_back(arr1[i++]);
    }
    while(j < m){
        arr3.push_back(arr2[j++]);
    }

    int o = n + m;

    if(o%2 == 0){
        return (arr3[o/2] + arr3[(o/2) - 1])/2;
    }else{
        return arr3[o/2];
    }
    }

    int betterSolution(vector<int> arr1, vector<int> arr2){
        int n = arr1.size();
        int m = arr2.size();
    
        int i = 0;
        int j = 0;

        int k = n+m;

        int reqCount1 = k/2;
        int reqCount2 = reqCount1 - 1;
        int count = 0;
        int reqEle1 = -1;
        int reqEle2 = -1;
        
        while( i < n && j < m){
            if(arr1[i] < arr2[j]){
                if(count == reqCount1){
                    reqEle1 = arr1[i];
                }
                if(count == reqCount2){
                    reqEle2 = arr1[i];
                }
                count++;
                i++;
            }else{
                if(count == reqCount1){
                    reqEle1 = arr2[j];
                }
                if(count == reqCount2){
                    reqEle2 = arr2[j];
                }
                count++;
                j++;
            }
        }
        while(i<n){
            if(count == reqCount1){
                reqEle1 = arr1[i];
            }
            if(count == reqCount2){
                reqEle2 = arr1[i];
            }
            count++;
            i++;
        }
        while(j<m){
            if(count == reqCount1){
                reqEle1 = arr2[j];
            }
            if(count == reqCount2){
                reqEle2 = arr2[j];
            }
            count++;
            j++;
        }

        if(k%2 == 1){
            return reqEle2;
        }

        return (reqEle1 + reqEle2)/2;
    }

    int optimalSolution(vector<int>& arr1, vector<int>& arr2){
        int n = arr1.size();
        int m = arr2.size();
        
        if(n > m){
            return optimalSolution(arr2, arr1);
        }

        int low = 0;
        int high = n;

        int left = (n+m+1)/2;
        int k = n + m;

        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2  = INT_MIN;
            int r1 = INT_MAX, r2  = INT_MAX;

            if(mid1 < n){
                r1 = arr1[mid1];
            }
            if(mid2 < m){
                r2 = arr2[mid2];
            }
            if(mid1 - 1 >= 0){
                l1 = arr1[mid1 - 1];
            }
            if(mid2 - 1 >= 0){
                l2 = arr2[mid2 - 1];
            }
            if(l1 <= r2 && l2 <= r1){
                if(k%2 == 1){
                    return max(l1, l2);
                }else{
                    return (max(l1, l2)+min(r1, r2))/2;
                }
            }else if(l1 > r2){
                high = mid1 - 1;
            }else{
                low = mid1 + 1;
            }
        }

        return 0;
    }
};

int main(){
    int n;
    cout << "Enter the n of the array you want: ";
    cin >> n;

    vector<int> arr1;
    cout << "Enter the value of "<< n << " numbers: ";
    for(int i = 0; i < n; i ++){
        int temp;
        cin >> temp;
        arr1.push_back(temp);
    }

    int m;
    cout << "Enter the m of the array you want: ";
    cin >> m;

    vector<int> arr2;
    cout << "Enter the value of "<< m << " numbers: ";
    for(int i = 0; i < m; i ++){
        int temp;
        cin >> temp;
        arr2.push_back(temp);
    }

    Solution sol;
    int result = sol.bruteForce(arr1, arr2);
    cout << "The ans is: " << result << "\n";

    return 0;
}