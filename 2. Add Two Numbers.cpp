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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        int carry = 0;
        while (l1 || l2) {
            int v1 = (l1)? l1->val: 0;
            int v2 = (l2)? l2->val: 0; 
            p->next = new ListNode((v1 + v2 + carry) % 10);
            carry = (v1 + v2 + carry) / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            p = p->next;
        }
        
        if (carry)
            p->next = new ListNode(carry);
        
        return dummy->next;
    }
};