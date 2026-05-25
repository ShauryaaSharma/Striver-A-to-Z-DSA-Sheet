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

    // Ordered Map
    map<int, int> mp;

    cout << "\nBuilding ordered map...\n";

    // Store frequencies
    for(int i = 0; i < n; i++){

        cout << "\nProcessing element: "
             << arr[i] << endl;

        cout << "Frequency before update = "
             << mp[arr[i]] << endl;

        mp[arr[i]]++;

        cout << "Frequency after update = "
             << mp[arr[i]] << endl;
    }

    // Print ordered map
    cout << "\n\nPrinting ordered map:\n";

    for(auto it : mp){

        cout << "Key = "
             << it.first
             << " | Frequency = "
             << it.second
             << endl;
    }

    cout << "\nNotice:\n";
    cout << "Elements are printed in SORTED ORDER.\n";

    // Queries
    int q;

    cout << "\nEnter number of queries: ";
    cin >> q;

    while(q--){

        int number;

        cout << "\nEnter number to find frequency: ";
        cin >> number;

        cout << "Frequency of "
             << number
             << " = "
             << mp[number]
             << endl;
    }

    cout << "\nProgram finished.\n";

    return 0;
}