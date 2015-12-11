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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(root==NULL) return ret;
        
        int nowLevel = 0;
        queue< pair<TreeNode*,int> >Q;
        Q.push( make_pair(root,nowLevel) );
        pair<TreeNode*,int> now,next;
        vector<int>temp;
        while(!Q.empty()){
            now = Q.front(); Q.pop();
            if(now.second>nowLevel){
                if(nowLevel%2) reverse(temp.begin(),temp.end());
                ret.push_back(temp);
                temp.clear();
                nowLevel++;
            }
            temp.push_back( (now.first)->val );
            if( (now.first)->left!=NULL )
                Q.push( make_pair((now.first)->left,nowLevel+1) );
            if( (now.first)->right!=NULL )
                Q.push( make_pair((now.first)->right,nowLevel+1) );
        }
        if(nowLevel%2) reverse(temp.begin(),temp.end());
        ret.push_back(temp);
        return ret;
    }
};