/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int res;
    void dfs(TreeNode *root,int last,int curlen){
        res = max(res,curlen);
        if(!root) return;
        //printf("%d %d %d\n",root->val,last,curlen);
        if(root->val  == last+1){
            curlen++;
        }
        else{
            curlen = 1;
        }
        dfs(root->left,root->val,curlen);
        dfs(root->right,root->val,curlen);
    }
    int longestConsecutive(TreeNode* root) {
        if(root==NULL) return 0;
        res = 0;
        dfs(root,root->val,1);
        return res;
    }
};


class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return search(root, nullptr, 0);
    }

    int search(TreeNode *root, TreeNode *parent, int len) {
        if (!root) return len;
        len = (parent && root->val == parent->val + 1)?len+1:1;
        return max(len, max(search(root->left, root, len), search(root->right, root, len)));
    }
};