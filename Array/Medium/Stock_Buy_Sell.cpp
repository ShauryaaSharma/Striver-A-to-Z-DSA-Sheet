#include <iostream>
#include <climits>
#include <map>
using namespace std;

class Solution
{
private:
public:
    // A = {2, 5, 7, 8, 2}, here the A[i] is the value of the stock on the ith day.
    // We have to maximize the profit by choosing on day to buy the stock and then another day to sell that stock.
    //  return max_profit.
    int bruteForce(int *A, int n)
    {
        int lowest_price = INT_MAX;
        int largest_price = INT_MIN;
        int smallest_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] < lowest_price)
            {
                lowest_price = A[i];
                smallest_index = i;
            }
        }
        if (smallest_index == n - 1)
        {
            return 0;
        }
        else
        {
            for (int j = smallest_index + 1; j < n; j++)
            {
                if (largest_price < A[j])
                {
                    largest_price = A[j];
                }
            }
        }
        return largest_price - lowest_price;
    }

    int betterApproch(int *A, int n)
    {
        int lowest_price = INT_MAX;
        int largest_price = INT_MIN;
        int smallest_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] < lowest_price)
            {
                lowest_price = A[i];
                smallest_index = i;
            }
        }
        if (smallest_index == n - 1)
        {
            return 0;
        }
        else
        {
            map<int, int> myHash;
            for(int i = smallest_index+1; i < n; i ++){
                myHash[A[i]]++;
            }
            for(auto element: myHash){
                if(element.first > largest_price){
                    largest_price = element.first;
                }
            }
        }
        return largest_price - lowest_price;
    }

    int optimalApproch(int *A, int n){
        int min_Price = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i < n; i ++){
            if(A[i] < min_Price){
                min_Price = A[i];
            }else{
                max_profit = max(max_profit, A[i] - min_Price);
            }
        }
        return max_profit;
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
    int result = s.betterApproch(A, n);

    cout << "The largest profit we get is: " << result;

    return 0;
}