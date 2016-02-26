/*
 Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
 
 Note:
 A subtree must include all of its descendants.
 Here's an example:
 10
 / \
 5  15
 / \   \
 1   8   7
 The Largest BST Subtree in this case is the highlighted one.
 The return value is the subtree's size, which is 3.
 Hint:
 
 You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
 Follow up:
 Can you figure out ways to solve it with O(n) time complexity?
 */

// Time Complexity: O(n)
// Space Complexity: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    struct Result {
        int size, lower, upper;
        Result(int _size, int _lower, int _upper)
        : size(_size), lower(_lower), upper(_upper) {}
    };
    
public:
    int largestBSTSubtree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
    Result dfs(TreeNode* root) {
        if (!root) {
            return Result(0, INT_MAX, INT_MIN);
        }
        Result left = dfs(root->left);
        Result right = dfs(root->right);
        if (left.size == -1 || right.size == -1 || root->val < left.upper ||
            root->val > right.lower) {
            return Result(-1, 0, 0);
        }
        int size = left.size + right.size + 1;
        res = max(res, size);
        return Result(size, min(root->val, left.lower),
                      max(root->val, right.upper));
    }
    
private:
    int res;
    
};