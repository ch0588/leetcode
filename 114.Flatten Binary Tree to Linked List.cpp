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
    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        
        root->right = pre;
        root->left = NULL;
        pre = root;    
    }
};