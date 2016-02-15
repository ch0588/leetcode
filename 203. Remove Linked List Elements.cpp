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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* vRoot = new ListNode(-1);
        ListNode *p = head, *last = vRoot;
        while (p) {
            if (p->val != val) {
                last->next = p;
                last = last->next;
                p = p->next;
                last->next = NULL;
            } else {
                p = p->next;
            }
        }
        return vRoot->next;
    }
};