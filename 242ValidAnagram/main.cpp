#include <unordered_map>
#include <iostream>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()) 
            return false;
        
        std::unordered_map<char,int> smap;
        std::unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) 
                return false;
        }
        
        return true;
    }
};

int main(){
    Solution sln;
    std::string isAnagram1 = "racecar";
    std::string isAnagram2 = "acercra";
    std::string isNotAnagram1 = "notananagram";
    std::string isNotAnagram2 = "definitelynot";

    std::cout << "Testing against an anagram results in a value of " << sln.isAnagram(isAnagram1, isAnagram2) << std::endl;

    std::cout << "Testing against a non-anagram results in a value of " << sln.isAnagram(isNotAnagram1, isNotAnagram2) << std::endl;

    return 0;
};