// Time Complexity: O(n)
// Space Complexity: O(logn)

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
    vector<vector<int> > res;
    void dfs(TreeNode *p, int sum, int need, vector<int> path) {
        if (!p) return;
        path.push_back(p->val);
        sum += p->val;
        if (!p->left && !p->right && sum == need) {
            res.push_back(path);
        }
        if (p->left) {
            dfs(p->left, sum, need, path);
        }
        if (p->right) {
            dfs(p->right, sum, need, path);
        }
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        res.clear();
        vector<int> path;
        dfs(root, 0, sum, path);
        return res;
    }
};
