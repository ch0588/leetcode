// Time Complexity: O(n)
// Space Complexity: O(h)

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
    vector<vector<int>> a;
    int height(TreeNode *p) {
        if (!p) return 0;
        return max(height(p->left), height(p->right)) + 1;
    }
    void dfs(TreeNode *p, int d) {
        if (!p) return;
        a[d].push_back(p->val);
        dfs(p->left, d + 1);
        dfs(p->right, d + 1);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        int h = height(root);
        a.resize(h);
        if (!root) return a;
        dfs(root, 0);
        return a;
    }
};
