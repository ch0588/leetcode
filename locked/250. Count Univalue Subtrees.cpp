/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
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
public:
    int cnt;
    bool isAll(TreeNode* root, int val) {
        if (root == NULL) return true;
        if (!isAll(root->left, root->val) | !isAll(root->right, root->val))
            return false;  // must | or ||,because || lazy return
        cnt++;
        return (root->val == val);
    }
    int countUnivalSubtrees(TreeNode* root) {
        cnt = 0;
        isAll(root, 0);
        return cnt;
    }
};