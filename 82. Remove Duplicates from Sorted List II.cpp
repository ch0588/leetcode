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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode *newHead = new ListNode(-1);
        ListNode *pre = newHead;
        pre->next = head;
        ListNode *cur = head;
        
        while (cur) {
            while (cur->next && pre->next->val == cur->next->val)
                cur = cur->next;
            if (pre->next == cur) {
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return newHead->next;
    }
};