class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numberFrequency;

        // Get the frequency of each number in nums
        // and store in hash map
        for(int key : nums){
            numberFrequency[key]++;
        }

        vector<int> mostFreq;

        // Store the frequency results, frequency being first and the number second
        vector<pair<int, int>> tempFreqStore;
        for(auto frequencyResult: numberFrequency){
            tempFreqStore.push_back({frequencyResult.second, frequencyResult.first});
        }

        // Sort the vector of frequency results by comparing count of numbers
        sort(tempFreqStore.begin(), tempFreqStore.end(), comparePairs);

        // Build return vector
        for(auto x : tempFreqStore){
            // If k is 0, return the array containing our numbers of highest frequency
            if(k == 0){
                return mostFreq;
            }
            mostFreq.push_back(x.second);
            k--;
        }
        
        return mostFreq;
    }

    static bool comparePairs(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    }
};