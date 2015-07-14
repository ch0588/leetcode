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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int pre = 0;
        ListNode *vRoot = new ListNode(-1);
        ListNode *head = vRoot;
        while(l1!=NULL || l2!=NULL){
            int x = pre;
            if(l1!=NULL){
                x += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                x += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode(x%10);
            head->next = node;
            head = head->next;
            pre = x/10;
        }
        if(pre!=0){
            ListNode *node = new ListNode(pre);
            head->next = node;
            head = head->next;
        }
        return vRoot->next;
    }
};
