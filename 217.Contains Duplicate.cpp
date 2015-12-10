/*
auto 与 unordered_multimap的用法
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_multimap<int, bool> hash;
        for (auto num: nums) {
            if (hash.find(num) != hash.end())
                return true;
            hash.insert(make_pair(num, true));
        }
        return false;
    }
};