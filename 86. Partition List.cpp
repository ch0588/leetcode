// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftRoot = new ListNode(-1), *rightRoot = new ListNode(-1);
        ListNode *cur = head, *left = leftRoot, *right = rightRoot;
        while (cur) {
            if (cur->val < x)
                left->next = cur, left = left->next;
            else
                right->next = cur, right = right->next;
            cur = cur->next;
        }
        
        if (rightRoot->next) right->next = NULL;
        
        // merge
        if (!leftRoot->next) return rightRoot->next;
        left->next = rightRoot->next;
        return leftRoot->next;
    }
};