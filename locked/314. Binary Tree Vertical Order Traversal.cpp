/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
    unordered_map<int,vector<int>>hash;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root){
            return res;
        }
        int left = 0, right = 0;
        vector<pair<TreeNode *, int>> Q{{root, 0}};
        for (int i = 0; i < Q.size(); ++i) {
            TreeNode *node = Q[i].first;
            int level = Q[i].second;
            
            hash[level].emplace_back(node->val);
            left = min(left,level);
            right = max(right,level);
            if(node->left)
                Q.push_back({node->left, level - 1});
            if(node->right)
                Q.push_back({node->right, level + 1});
        }
        res.resize(right-left+1);
        for(auto it:hash){
            res[ it.first - left ] = it.second;
        }
        return res;
    }
};