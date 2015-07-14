/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL)  return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int dl = -1, dr = -1;
        if(root->left) dl = maxDepth(root->left);
        if(root->right) dr = maxDepth(root->right);
        return 1+max(dl,dr);
    }
};
