// Time Complexity: O(n)
// Space Complexity: O(1)

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
    vector<vector<int>> ret;
    void dfs(TreeNode *p, int d) {
        if (p == NULL) return;
        if (d >= (int)ret.size()) {
            vector<int> t;
            t.push_back(p->val);
            ret.push_back(t);
        } else {
            ret[d].push_back(p->val);
        }
        dfs(p->left, d + 1);
        dfs(p->right, d + 1);
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        ret.clear();
        dfs(root, 0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
