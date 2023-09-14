#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
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
    int target = 9;
    vector<int> validInputForTarget = {2, 7, 11, 15};
    vector<int> invalidInputForTarget = {2, 10, 11, 15};

    cout << "Checking a vector which contains the target" << endl;
    outVector(validInputForTarget);
    cout << "Has result of ";
    outVector(sln.twoSum(validInputForTarget, target));

    cout << "Checking a vector which does not contain the target" << std::endl;
    outVector(invalidInputForTarget);
    cout << "Has result of ";
    outVector(sln.twoSum(invalidInputForTarget, target));
    cout << "look it's empty!" << endl;
    return 0;
};