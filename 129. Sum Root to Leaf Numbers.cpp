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
    int sum;
    void dfs(TreeNode *p, int s) {
        if (!p) return;
        s = s * 10 + p->val;
        if (!p->left && !p->right) {
            sum += s;
            return;
        }
        if (p->left) dfs(p->left, s);
        if (p->right) dfs(p->right, s);
    }
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};
