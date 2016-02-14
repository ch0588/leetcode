// Time Complexity: O(n+m)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *cur = headA;
        while (cur) lenA++, cur = cur->next;
        cur = headB;
        while (cur) lenB++, cur = cur->next;
        
        if (lenA < lenB) {
            int k = lenB - lenA;
            while (k--) headB = headB->next;
        }
        if (lenA > lenB) {
            int k = lenA - lenB;
            while (k--) headA = headA->next;
        }
        
        while (headA && headB) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};