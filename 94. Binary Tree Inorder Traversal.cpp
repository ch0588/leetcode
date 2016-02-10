// https://leetcode.com/discuss/10927/three-methods-to-solve-c
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> S;
        vector<int> res;
        while (!S.empty() || cur) {
            if (cur) {
                S.push(cur);
                cur = cur->left;
            } else {
                TreeNode* tmp = S.top();
                S.pop();
                res.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return res;
    }
};