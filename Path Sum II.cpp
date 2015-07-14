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
    vector<vector<int> >ret;
    void dfs(TreeNode *p,int sum,int need,vector<int>path){
        if(p==NULL) return;
        path.push_back(p->val);
        sum+=p->val;
        if(p->left==NULL && p->right==NULL && sum==need) {
            ret.push_back(path);
        }
        if(p->left!=NULL){
            dfs(p->left,sum,need,path);
        }
        if(p->right!=NULL){
            dfs(p->right,sum,need,path);
        }
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ret.clear();
        vector<int>path;
        dfs(root,0,sum,path);
        return ret;
    }
};
