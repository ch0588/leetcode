// Time Complexity: O(n)
// Space Complexity: O(logn)

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
    TreeNode* rebuildTree(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir) return NULL;
        
        TreeNode* node = new TreeNode(preorder[pl]);
        
        int pos = il, lenLeft = 0;
        while (pos <= ir) {
            if (inorder[pos] == preorder[pl]) break;
            lenLeft++;
            pos++;
        }
        // rebuild left
        node->left = rebuildTree(preorder, inorder, pl + 1, pl + lenLeft, il, pos - 1);
        // rebuild right
        node->right = rebuildTree(preorder, inorder, pl + lenLeft + 1, pr, pos + 1, ir);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* pRoot = NULL;
        pRoot = rebuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return pRoot;
    }
};