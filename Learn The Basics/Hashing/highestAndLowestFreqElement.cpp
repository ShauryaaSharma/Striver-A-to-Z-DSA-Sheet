#include <iostream>
#include <map>
using namespace std;

int main(){

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "\nEnter array elements:\n";

    // Input array
    for(int i = 0; i < n; i++){

        cout << "Enter element at index "
             << i << ": ";

        cin >> arr[i];
    }

    // Ordered map for frequency counting
    map<int, int> mp;

    cout << "\nBuilding frequency map...\n";

    // Count frequencies
    for(int i = 0; i < n; i++){

        cout << "\nProcessing element: "
             << arr[i] << endl;

        cout << "Old frequency = "
             << mp[arr[i]] << endl;

        mp[arr[i]]++;

        cout << "Updated frequency = "
             << mp[arr[i]] << endl;
    }

    // Print map
    cout << "\n\nFinal Frequency Map:\n";

    for(auto it : mp){

        cout << "Element = "
             << it.first
             << " | Frequency = "
             << it.second
             << endl;
    }

    // Variables for highest and lowest frequency
    int maxFreq = 0;
    int minFreq = n;

    int maxElement = -1;
    int minElement = -1;

    cout << "\nFinding highest and lowest frequency...\n";

    // Traverse map
    for(auto it : mp){

        int element = it.first;
        int freq = it.second;

        cout << "\nChecking element: "
             << element << endl;

        cout << "Frequency = "
             << freq << endl;

        // Highest frequency
        if(freq > maxFreq){

            maxFreq = freq;
            maxElement = element;

            cout << "New highest frequency found.\n";
        }

        // Lowest frequency
        if(freq < minFreq){

            minFreq = freq;
            minElement = element;

            cout << "New lowest frequency found.\n";
        }
    }

    // Final answer
    cout << "\n\nHighest frequency element = "
         << maxElement
         << endl;

    cout << "Lowest frequency element = "
         << minElement
         << endl;

    return 0;
}