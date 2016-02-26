/*
 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 
 Note:
 Given target value is a floating point.
 You may assume k is always valid, that is: k ≤ total nodes.
 You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 Follow up:
 Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 
 Hint:
 
 Consider implement these two helper functions:
 getPredecessor(N), which returns the next smaller node to N.
 getSuccessor(N), which returns the next larger node to N.
 */

// Time Complexity: O(h+k) h:height of BST
// Space Complexity: O(h)

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        initializeSuccessorStack(root, target);
        initializePredecessorStack(root, target);
        
        vector<int> res;
        if (!succ.empty() && !pred.empty() && succ.top()->val == pred.top()->val) {
            getNextPredecessor();
        }
        while (k-- > 0) {
            if (succ.empty()) {
                res.emplace_back(getNextPredecessor());
            } else if (pred.empty()) {
                res.emplace_back(getNextSuccessor());
            } else {
                double succ_diff = fabs((double)succ.top()->val - target);
                double pred_diff = fabs((double)pred.top()->val - target);
                if (succ_diff < pred_diff) {
                    res.emplace_back(getNextSuccessor());
                } else {
                    res.emplace_back(getNextPredecessor());
                }
            }
        }
        return res;
    }
    
private:
    stack<TreeNode *> succ, pred;
    void initializeSuccessorStack(TreeNode* root, double target) {
        while (root) {
            if (root->val == target) {
                succ.push(root);
                break;
            } else if (root->val > target) {
                succ.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    void initializePredecessorStack(TreeNode* root, double target) {
        while (root) {
            if (root->val == target) {
                pred.push(root);
                break;
            } else if (root->val < target) {
                pred.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
    int getNextSuccessor() {
        TreeNode* cur = succ.top();
        int res = cur->val;
        succ.pop();
        cur = cur->right;
        while (cur) {
            succ.push(cur);
            cur = cur->left;
        }
        return res;
    }
    int getNextPredecessor() {
        TreeNode* cur = pred.top();
        int res = cur->val;
        pred.pop();
        cur = cur->left;
        while (cur) {
            pred.push(cur);
            cur = cur->right;
        }
        return res;
    }
};