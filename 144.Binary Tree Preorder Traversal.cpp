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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode*cur = root;
        stack<TreeNode*>S;
        vector<int>res;
        while(!S.empty() || cur){
            if(cur){
                res.push_back(cur->val);
                S.push(cur);
                cur = cur->left;
            }
            else{
                cur = S.top();
                S.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};