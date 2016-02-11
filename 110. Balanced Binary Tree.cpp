// Time Complexity: O(n)
// Space Complexity: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root) {
    if (root == NULL) return 0;
    int ld = dfs(root->left);
    int rd = dfs(root->right);
    if (ld < 0 || rd < 0 || abs(ld - rd) > 1)
        return -1;
    else
        return ld < rd ? rd + 1 : ld + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (dfs(root) < 0)
        return false;
    else
        return true;
}