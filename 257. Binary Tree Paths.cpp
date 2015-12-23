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
    vector<string>res;
    void dfs(vector<int>cur,TreeNode *p){
        if(p==NULL) return;
        cur.push_back(p->val);
        
        if(!p->left && !p->right){
            int n = cur.size();
            if(n==0) return;
            string t = to_string(cur[0]);
            for(int i=1; i<n; ++i)
                t += ("->"+to_string(cur[i]));
            res.push_back(t);
            return;
        }
        
        dfs(cur,p->left);
        dfs(cur,p->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if(root==NULL) return res;
        vector<int>cur;
        dfs(cur,root);
        return res;
    }
};