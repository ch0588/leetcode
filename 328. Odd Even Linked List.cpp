// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        ListNode* cur = even->next;
        while (cur) {
            odd->next = cur;
            odd = odd->next;
            cur = cur->next;
            odd->next = NULL;
            if (cur) {
                even->next = cur;
                even = even->next;
                cur = cur->next;
                even->next = NULL;
            }
        }
        even->next = NULL;
        odd->next = evenHead;
        return head;
    }
};