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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode *> subTree;
            return subTree;
        }
        return generateTrees(1, n);
    }
    vector<TreeNode *> generateTrees(int l, int r) {
        vector<TreeNode *> subTree;
        if (l > r) {
            subTree.push_back(NULL);
            return subTree;
        }
        for (int k = l; k <= r; ++k) {
            vector<TreeNode *> left = generateTrees(l, k - 1);
            vector<TreeNode *> right = generateTrees(k + 1, r);
            for (int i = 0; i < left.size(); ++i)
                for (int j = 0; j < right.size(); ++j) {
                    TreeNode *node = new TreeNode(k);
                    node->left = left[i];
                    node->right = right[j];
                    subTree.push_back(node);
                }
        }
        return subTree;
    }
};