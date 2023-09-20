using namespace std;
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        if(strs.size() == 1){
            groupedAnagrams.push_back(strs);
            return groupedAnagrams;
        }

        unordered_map <string, vector<string>> charMap;
        // Generate a key for each string by sorting the characters in the string
        // then add the original string to the vector of strings who's key is the 
        // set of characters
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            charMap[key].push_back(s);
        }

        // Collect the groups of strings containing the same characters into 
        // distinct vector<string> for return
        for(auto charKey : charMap){
            groupedAnagrams.push_back(charKey.second);
        }

        return groupedAnagrams;
    }
};

int main(){
    Solution sln;
    vector<string> many = {"eat","tea","tan","ate","nat","bat"};
    vector<string> oneEmpty = {""};
    vector<string> oneEntry = {"a"};

    vector<vector<string>> manyResult = sln.groupAnagrams(many);
    vector<vector<string>> oneEmptyResult = sln.groupAnagrams(oneEmpty);
    vector<vector<string>> oneEntryResult = sln.groupAnagrams(oneEntry);

    cout << "Input of [";
    for(const string& s : many){
        cout << s << ", ";
    }
    cout << "] gets result of: [";
    for(const auto& mR: manyResult){
        cout << "[";
        for(auto m : mR){
            cout << m << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
    cout << endl << endl;

    cout << "Input of [";
    for(const string& s : oneEmpty){
        cout << s << ", ";
    }
    cout << "] gets result of: [";
    for(const auto& oneEntryRes: oneEmptyResult){
        cout << "[";
        for(auto resEntry : oneEntryRes){
            cout << resEntry << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
    cout << endl << endl;

    cout << "Input of [";
    for(const string& s : oneEntry){
        cout << s << ", ";
    }
    cout << "] gets result of: [";
    for(const auto& oE: oneEntryResult){
        cout << "[";
        for(const auto& res : oE){
            cout << res << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;


    return 0;
};