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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast) {  // 1,2,3,4->3  1,2,3->3    second>=first
            fast = fast->next;
            if (!fast) break;
            fast = fast->next;
            slow = slow->next;
        }
        
        slow = reverse(slow);
        ListNode* cur = head;
        
        while (slow && cur) {
            if (slow->val != cur->val) return false;
            slow = slow->next;
            cur = cur->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* p) {
        ListNode *cur = p, *pre = NULL;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};