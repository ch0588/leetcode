/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
For example,
Given n = 2, return ["11","69","88","96"].
*/

// Time Complexity: O(n^2 * 5^(n/2))
// Space Complexity: O(n)

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammaticRecu(n, n);
    }
    
    vector<string> findStrobogrammaticRecu(const int n, int k) {
        if (k == 0) {
            return {""};
        } else if (k == 1) {
            return {"0", "1", "8"};
        }
        
        vector<string> result;
        for (const auto& num : findStrobogrammaticRecu(n, k - 2)) {
            for (const auto& kvp : lookup) {
                if (n != k || kvp.first != "0") {
                    result.emplace_back(kvp.first + num + kvp.second);
                }
            }
        }
        return result;
    }
    
private:
    const unordered_map<string, string> lookup{
        {"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}};
};