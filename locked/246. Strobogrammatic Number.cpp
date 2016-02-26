/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> hash{
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int n = num.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            if (hash.find(num[l]) == hash.end() || hash[num[l]] != num[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};