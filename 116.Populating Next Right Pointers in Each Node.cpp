/*
only two pointer space
leftest pointer is the most left side
deal it by row
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        TreeLinkNode *leftest = root, *cur = NULL;
        while(leftest->left){
            cur = leftest;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next)   cur->right->next = cur->next->left;
                cur = cur->next;
            }
            leftest = leftest->left;
        }
    }
};