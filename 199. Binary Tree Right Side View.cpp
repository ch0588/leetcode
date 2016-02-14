// Time Complexity: O(n)
// Space Complexity: O(h)

/*
 root right left的顺序遍历，每层第一次出现的就是
 */

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
    void dfs(vector<int>& res, TreeNode* root, int depth) {
        if (root == NULL) return;
        if ((int)res.size() == depth) res.push_back(root->val);
        dfs(res, root->right, depth + 1);
        dfs(res, root->left, depth + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};