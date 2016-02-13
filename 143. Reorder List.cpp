// Time Complexity: O(n)
// Space Complexity: O(1)

/*
 三步
 1.找到中点，将原链表分为前后两半，如果原链表为奇数，则第一段比第二段多一个元素
 2.将后半段链表逆序
 3.交叉合并和两段链表。
 */

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
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *pre = NULL, *cur = head;
        while (cur != NULL) {
            ListNode *t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) return;
        // split tow linked
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL) {
            fast = fast->next->next;
            if (fast == NULL) break;
            slow = slow->next;
        }
        // slow is last node in first half, second.size<=first.size
        ListNode *secondHead = slow->next;
        slow->next = NULL;
        
        // reverse the second half list
        secondHead = reverse(secondHead);
        
        // cross merge two list
        ListNode *cur = head;
        
        while (cur != NULL) {
            ListNode *t1 = cur->next;
            cur->next = secondHead;
            if (secondHead == NULL) break;
            ListNode *t2 = secondHead->next;
            secondHead->next = t1;
            cur = t1;
            secondHead = t2;
        }
    }
};