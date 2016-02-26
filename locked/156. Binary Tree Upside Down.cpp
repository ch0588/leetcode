/*
Given a binary tree where all the right nodes are either leaf nodes with a
sibling (a left node that shares the same parent node) or empty, flip it upside
down and turn it into a tree where the original right nodes turned into left
leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) return NULL;
        if (root->left == NULL) return root;
        TreeNode* left = root->left;
        TreeNode* nr = upsideDownBinaryTree(root->left);
        left->left = root->right;
        left->right = root;
        root->left = root->right = NULL;
        return nr;
    }
};