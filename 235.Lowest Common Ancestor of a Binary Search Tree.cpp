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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==NULL || q==NULL) return root;
        TreeNode* cur = root;
        if(p->val > q->val) swap(p,q);
        while(cur){
            if(cur->val >= p->val && cur->val <= q->val ) break;
            if( cur->val > q->val ) cur = cur->left;
            else cur = cur->right;
        }
        return cur;
    }
};