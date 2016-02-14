// Time Complexity: average O(1)
// Space Complexity: average O(h)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) { pushAll(root); }
    
    /** @return whether we have a next smallest number */
    bool hasNext() { return !S.empty(); }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = S.top();
        S.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
private:
    stack<TreeNode *> S;
    void pushAll(TreeNode *p) {
        while (p) {
            S.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */