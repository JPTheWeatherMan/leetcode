
// Time Complexity: O(n)
// We use an unordered set to keep track of characters that we have already
// encountered. If the character is already contained in the set and it 
// is not the terminating value we know that it is indeed a duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};