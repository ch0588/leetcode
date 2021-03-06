// Time Complexity: O(n)
// Space Complexity: O(1)

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
        TreeLinkNode *now, *tail, *head;
        // base BFS use next info
        // now is current level travller,head is next level most left element,tail
        // is next level most right until now
        now = root;
        head = tail = NULL;
        while (now) {
            if (now->left) {
                if (tail)
                    tail = tail->next = now->left;
                else
                    head = tail = now->left;
            }
            if (now->right) {
                if (tail)
                    tail = tail->next = now->right;
                else
                    head = tail = now->right;
            }
            
            if (!(now = now->next)) {
                now = head;
                head = tail = NULL;
            }
        }
    }
};