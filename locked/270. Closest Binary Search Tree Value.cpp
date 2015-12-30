/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
 */

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
    int closestValue(TreeNode* root, double target) {
        if(root==NULL) return INT_MAX;
        
        int child=INT_MAX;
        if((double)root->val > target){
            child = closestValue(root->left,target);
        }
        else{
            child = closestValue(root->right,target);
        }
        
        if(child==INT_MAX) return root->val;
        return fabs(target-child)<fabs(target-root->val) ? child : root->val;
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto kid = target < a ? root->left : root->right;
        if (!kid) return a;
        int b = closestValue(kid, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};