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
    bool isValidBST(TreeNode* root,long long lower,long long upper) {
        if(root==NULL) return true;
        return root->val > lower && root->val < upper && isValidBST(root->left,lower,root->val) && isValidBST(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,-21474836470LL,21474836470);
    }
};

//used int may cause int stackoverflow

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
    bool isValidBST(TreeNode* root,TreeNode* lower,TreeNode* upper) {
        if(root==NULL) return true;
        if(lower && root->val <= lower->val) return false;
        if(upper && root->val >= upper->val) return false;
        return isValidBST(root->left,lower,root) && isValidBST(root->right,root,upper);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL, NULL);
    }
};