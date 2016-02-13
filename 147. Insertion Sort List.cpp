// Time Complexity: O(n^2)
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *father = new ListNode(INT_MIN);
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *pre = father, *p = father->next;
            while (p != NULL) {
                if (p->val > cur->val) {
                    break;
                }
                pre = p;
                p = p->next;
            }
            pre->next = cur;
            cur = cur->next;
            pre->next->next = p;
        }
        return father->next;
    }
};
