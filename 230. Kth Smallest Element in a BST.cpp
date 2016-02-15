// Time Complexity: O(max(h, k))
// Space Complexity: O(min(h, k))

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
    int count = 0;
    int num = 0;
    
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        dfs(root);
        return num;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        
        count--;
        if (count == 0) {
            num = root->val;
            return;
        }
        if (count < 0) return;
        
        dfs(root->right);
    }
};