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
    TreeNode* rebuildTree(vector<int>& inorder, vector<int>& postorder,int il,int ir,int pl,int pr){
        if( il>ir || pl>pr ) return NULL;
        
        TreeNode* node = new TreeNode(postorder[pr]);
        
        int pos = il,lenLeft=0;
        while(pos<=ir){
            if(inorder[pos]==postorder[pr]) break;
            lenLeft++;
            pos++;
        }
        //rebuild left
        node->left = rebuildTree(inorder,postorder, il,pos-1, pl,pl+lenLeft-1);
        //rebuild right
        node->right = rebuildTree(inorder,postorder, pos+1,ir, pl+lenLeft,pr-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* pRoot = NULL;
        pRoot = rebuildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        return pRoot;
    }
};