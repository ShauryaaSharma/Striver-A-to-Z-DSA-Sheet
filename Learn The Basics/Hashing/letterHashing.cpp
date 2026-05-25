#include <iostream>
using namespace std;

int main(){

    string s;

    cout << "Enter a string: ";
    cin >> s;

    // Hash array for lowercase letters
    int hash[26] = {0};

    cout << "\nBuilding hash array for characters...\n";

    // Storing frequencies
    for(int i = 0; i < s.size(); i++){

        char ch = s[i];

        cout << "\nProcessing character: " << ch << endl;

        int index = ch - 'a';

        cout << "Character index = " << index << endl;

        cout << "Frequency before update = "
             << hash[index] << endl;

        hash[index]++;

        cout << "Frequency after update = "
             << hash[index] << endl;
    }

    // Printing hash array
    cout << "\n\nFinal character frequencies:\n";

    for(int i = 0; i < 26; i++){

        if(hash[i] > 0){

            char ch = i + 'a';

            cout << "Character "
                 << ch
                 << " appeared "
                 << hash[i]
                 << " times.\n";
        }
    }

    // Queries
    int q;

    cout << "\nEnter number of queries: ";
    cin >> q;

    while(q--){

        char character;

        cout << "\nEnter character to find frequency: ";
        cin >> character;

        cout << "Frequency of "
             << character
             << " = "
             << hash[character - 'a']
             << endl;
    }

    cout << "\nProgram finished.\n";

    return 0;
}