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
 ����ansʱ��p�ڵ�+���Ҷ��ӵ�����ֵ����ʱ·��Ϊ^��״
 return ʱֻ�������Ҷ����нϴ��һ����
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
