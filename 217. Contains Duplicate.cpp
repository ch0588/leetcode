// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto num: nums) {
            if (hash[num] == 1)
                return true;
            hash[num] = 1;
        }
        return false;
    }
    
};