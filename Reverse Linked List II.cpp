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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL) return NULL;
        if(n==m) return head;

        ListNode *begin = head;
        ListNode *beginPre = NULL;
        for(int i=2; i<=m; ++i){
            beginPre = begin;
            begin = begin->next;
        }
        ListNode *pre = begin;
        ListNode *p = begin->next;
        for(int i=0; i<(n-m); ++i){
            ListNode *next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        if(beginPre==NULL) head=pre;
        else beginPre->next = pre;

        begin->next = p;
        return head;
    }
};
