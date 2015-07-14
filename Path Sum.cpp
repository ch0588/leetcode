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
    bool dfs(TreeNode *p,int sum,int need){
        if(p==NULL) return false;
        sum+=p->val;
        if(p->left==NULL && p->right==NULL && sum==need) return true;
        bool fl=false,fr=false;
        if(p->left!=NULL)  fl = dfs(p->left,sum,need);
        if(p->right!=NULL) fr = dfs(p->right,sum,need);
        if(fl||fr) return true;
        else return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root,0,sum);
    }
};
