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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n < 1)  return head;

        ListNode *cur = head;
        int len = 0;
        while (cur) {
            len++; cur=cur->next;
        }
        
        if(n > len) return head;
        n = len - n + 1;

        ListNode *fa = new ListNode(-1);
        fa->next = head;
        ListNode *pre = fa;
        cur = head;
        for (int i = 1; i < n; ++i) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return fa->next;
    }
};