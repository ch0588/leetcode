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
    int minDepth(TreeNode *root) {
        return minDepth(root,false);
    }
    int minDepth(TreeNode *p,bool hasBrother){
        if(!p) return hasBrother?INT_MAX:0;
        return 1 + min( minDepth(p->left,p->right!=NULL),minDepth(p->right,p->left!=NULL) );
    }

};
