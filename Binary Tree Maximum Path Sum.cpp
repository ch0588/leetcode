/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 更新ans时，p节点+左右儿子的最优值，此时路径为^形状
 return 时只返回左右儿子中较大的一个。
 */
class Solution {
    int ans;
    int dfs(TreeNode *p){
        if(p==NULL) return 0;
        if(p->left==NULL && p->right==NULL) {
            ans = max(ans,p->val);
            return p->val;
        }

        int l = 0, r = 0;
        if(p->left!=NULL) l = dfs(p->left);
        if(p->right!=NULL) r = dfs(p->right);
        int ret = p->val;
        if(l>0) ret+=l;
        if(r>0) ret+=r;

        ans = max(ans,ret);
        return max(l,r)>0?p->val+max(l,r):p->val;
    }
public:
    int maxPathSum(TreeNode *root) {
        if(root==NULL) return 0;
        ans = root->val;
        int t = dfs(root);
        return ans;
    }
};
