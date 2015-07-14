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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int>ret;
        if(!root) return ret;

        stack<TreeNode *>S;
        TreeNode *cur=root;
        while( !S.empty() || cur!=NULL ){
            if(cur!=NULL){
                S.push(cur);
                ret.push_back(cur->val);
                cur = cur->left;
            }
            else{
                cur = S.top();
                S.pop();
                cur = cur->right;
            }
        }
        return ret;
    }
};
