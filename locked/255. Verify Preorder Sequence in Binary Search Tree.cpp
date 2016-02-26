/*
 Given an array of numbers, verify whether it is the correct preorder traversal
 sequence of a binary search tree.
 
 You may assume each number in the sequence is unique.
 
 Follow up:
 Could you do it using only constant space complexity?
 */

// Time:  O(n)
// Space: O(h)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> path;
        for (auto& p : preorder) {
            if (p < low) {
                return false;
            }
            while (!path.empty() && p > path.top()) {
                // Traverse to its right subtree now.
                // Use the popped values as a lower bound because
                // we shouldn't come across a smaller number anymore.
                low = path.top();
                path.pop();
            }
            path.emplace(p);
        }
        return true;
    }
};

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN, i = -1;
        for (auto& p : preorder) {
            if (p < low) {
                return false;
            }
            while (i >= 0 && p > preorder[i]) {
                low = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};