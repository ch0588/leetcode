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
    int dfs(TreeNode *p){
        if(p==NULL) return 0;
        return max( dfs(p->left),dfs(p->right) ) + 1;
    }
    void dfs2(TreeNode *p,int d){
        if(p==NULL) return;
        a[d].push_back(p->val);
        dfs2(p->left,d+1);
        dfs2(p->right,d+1);
    }
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        int n = dfs(root);
        a.resize(n);
        if(root==NULL) return a;
        dfs2(root,0);

        return a;
    }
};
