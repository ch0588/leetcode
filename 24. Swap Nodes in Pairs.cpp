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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *prev = &dummy, *cur=prev->next, *next=cur->next;
        while (next) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            
            prev = cur;
            cur = cur->next;
            next = cur? cur->next: NULL;
        }
        return dummy.next;
    }
};