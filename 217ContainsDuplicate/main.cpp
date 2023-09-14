#include <unordered_set>
#include <iostream>
#include <vector>

// Time Complexity: O(n)
// We use an unordered set to keep track of characters that we have already
// encountered. If the character is already contained in the set and it 
// is not the terminating value we know that it is indeed a duplicate.
class Solution {
public:
    bool containsDuplicates(std::vector<int>& nums) {
        std::unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

void outVector(std::vector<int> a){
    for(const auto& e : a){
        std::cout << e << ", ";
    }
    std::cout << "\n";
    return;
}

int main(){
    Solution sln;
    std::vector<int> setWithDuplicates = {1, 2, 3, 4, 1};
    std::vector<int> setWithoutDuplicates = {1, 2, 3, 4, 5};
    
    std::cout << "Checking a vector with duplicates" << std::endl;
    outVector(setWithDuplicates);
    std::cout << "Has result of " << sln.containsDuplicates(setWithDuplicates) << std::endl;

    std::cout << "Checking a vector without duplicates" << std::endl;
    outVector(setWithoutDuplicates);
    std::cout << "Has result of " << sln.containsDuplicates(setWithoutDuplicates) << std::endl;
    return 0;
};