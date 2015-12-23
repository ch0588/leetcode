/*
morris traversal可以常数空间遍历二叉树
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
    void recoverTree(TreeNode *root) {
        TreeNode* cur = 0;
        TreeNode* pre = 0;
        TreeNode* p1 = 0;
        TreeNode* p2 = 0;
        TreeNode* preCur = 0;

        bool found = false;

        if(!root) {
            return;
        }

        cur = root;
        while(cur) {
            if(!cur->left) {
                //记录p1和p2
                if(preCur && preCur->val > cur->val) {
                    if(!found) {
                        p1 = preCur;
                        found = true;
                    }
                    p2 = cur;
                }

                preCur = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if(!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    //记录p1和p2
                    if(preCur->val > cur->val) {
                        if(!found) {
                            p1 = preCur;
                            found = true;
                        }
                        p2 = cur;
                    }
                    preCur = cur;
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }

        if(p1 && p2) {
            int t = p1->val;
            p1->val = p2->val;
            p2->val = t;
        }
    }
};