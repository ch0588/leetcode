// Time Complexity: O(n)
// Space Complexity: O(logn)

/*
 自底向上的方法
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    //[start,end]
    TreeNode *sortedListToBST(ListNode *&list, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedListToBST(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        TreeNode *rightChild = sortedListToBST(list, mid + 1, end);
        parent->right = rightChild;
        return parent;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
};