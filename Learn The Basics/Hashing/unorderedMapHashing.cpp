#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "\nEnter the array elements:\n";

    // Input array
    for(int i = 0; i < n; i++){

        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    // Unordered Map
    unordered_map<int, int> umap;

    cout << "\nBuilding unordered_map...\n";

    // Storing frequencies
    for(int i = 0; i < n; i++){

        cout << "\nProcessing element: " << arr[i] << endl;

        cout << "Frequency before update = "
             << umap[arr[i]] << endl;

        umap[arr[i]]++;

        cout << "Frequency after update = "
             << umap[arr[i]] << endl;
    }

    // Printing unordered_map
    cout << "\n\nContents of unordered_map:\n";

    for(auto it : umap){

        cout << "Key = " << it.first
             << " | Frequency = "
             << it.second << endl;
    }

    cout << "\nNotice:\n";
    cout << "unordered_map DOES NOT store elements in sorted order.\n";
    cout << "The order may look random.\n";

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
             << umap[number]
             << endl;
    }

    cout << "\nProgram finished.\n";

    return 0;
}