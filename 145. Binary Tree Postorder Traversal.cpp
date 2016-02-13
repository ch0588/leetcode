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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* pre = root;
        stack<TreeNode*> S;
        vector<int> res;
        
        if (root == NULL) return res;
        
        S.push(root);
        while (!S.empty()) {
            TreeNode* tmp = S.top();
            if (tmp->left == pre || tmp->right == pre || (!tmp->left && !tmp->right)) {
                res.push_back(tmp->val);
                pre = tmp;
                S.pop();
            } else {
                if (tmp->right) S.push(tmp->right);
                if (tmp->left) S.push(tmp->left);
            }
        }
    }
};