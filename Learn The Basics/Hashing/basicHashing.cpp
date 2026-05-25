#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "\nEnter the elements of the array:\n";

    // Input array
    for(int i = 0; i < n; i++){
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    cout << "\nArray entered successfully!\n";

    // Hash array
    int hash[13] = {0};

    cout << "\nBuilding hash array...\n";

    // Storing frequencies
    for(int i = 0; i < n; i++){

        cout << "\nProcessing element: " << arr[i] << endl;

        cout << "Before update -> hash[" 
             << arr[i] << "] = "
             << hash[arr[i]] << endl;

        hash[arr[i]] += 1;

        cout << "After update -> hash[" 
             << arr[i] << "] = "
             << hash[arr[i]] << endl;
    }

    // Printing full hash array
    cout << "\n\nFinal Hash Array:\n";

    for(int i = 0; i < 13; i++){
        cout << "Index " << i
             << " --> Frequency = "
             << hash[i] << endl;
    }

    // Understanding order
    cout << "\nExplanation of order:\n";

    for(int i = 0; i < 13; i++){

        if(hash[i] > 0){

            cout << "Number " << i
                 << " appeared "
                 << hash[i]
                 << " times in the array.\n";
        }
    }

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
             << hash[number]
             << endl;
    }

    cout << "\nProgram finished.\n";

    return 0;
}