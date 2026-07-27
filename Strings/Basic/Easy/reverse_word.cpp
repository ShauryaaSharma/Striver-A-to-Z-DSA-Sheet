#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
public:
    string bruteForce(string s)
    {
        string temp;
        int n = s.size();
        for (int i = n - 1; i >= 0;)
        {
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
            if ( i < 0){
                break;
            }
            int end = i;

            while (i > 0 && s[i] != ' ')
            {
                i--;
            }

            int start = i + 1;

            for (int j = start; j <= end; j++)
            {
                temp += s[j];
            }
            if (i >= 0)
            {
                temp += ' ';
            }

        }
        return temp;
    }

    // string betterApproch(string s)
    // {
    //     int n = s.size();
    //     string result = "";
    //     for (int i = n - 1; i >= 0;)
    //     {
    //         while (i >= 0 && s[i] == ' ')
    //         {
    //             i--;
    //         }
    //         if ( i < 0){
    //             break;
    //         }
    //         int end = i;

    //         while (i > 0 && s[i] != ' ')
    //         {
    //             i--;
    //         }

    //         int start = i + 1;

    //         string word = s.substr(start, end - i);

    //         if (!result.empty())
    //         {
    //             result += ' ';
    //         }

    //         result += word;

    //     }
    //     return result;
    // }

    string optimalApproch(string s){
        vector<string> preRes;
        string word;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                word += s[i];
            }else if(!word.empty()){
                preRes.push_back(word);
                word = "";
            }
        }
        if(!word.empty()){
            preRes.push_back(word);
        }

        reverse(preRes.begin(), preRes.end());

        string result ="";
        for(int i = 0; i < preRes.size(); i++){
            result += preRes[i];
            if(i < preRes.size() - 1){
                result += " ";
            }
        }
        return result;
    }
};

int main()
{
    string word;
    cout << "Enter a single string: ";
    getline(cin, word);
    cout << "You had entered: " << word << endl;
    Solution sol;
    string result = sol.optimalApproch(word);
    cout << "You output is " << result << endl;
    return 0;
}