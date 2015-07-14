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
    void dfs(TreeNode *p,int s){
        if(p==NULL) return;
        s = s*10 + p->val;
        if(p->left==NULL && p->right==NULL) {
            sum +=s;
            return;
        }
        if(p->left!=NULL) dfs(p->left,s);
        if(p->right!=NULL) dfs(p->right,s);
    }
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root,0);
        return sum;
    }
};
