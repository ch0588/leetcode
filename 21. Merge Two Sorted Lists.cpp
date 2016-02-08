// Time Complexity: O(n)
// Space Complexity: O(n)

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return NULL;
        ListNode * head = new ListNode(-1);
        ListNode * pre = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        while (l1) {
            pre->next = l1;
            pre = l1;
            l1 = l1->next;
        }
        while (l2) {
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        }
        return head->next;
    }
};