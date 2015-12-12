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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        
        int len = 0;
        ListNode *cur=head,*last=NULL;
        while(cur!=NULL){
            len++;
            last = cur;
            cur = cur->next;
        }
        
        k = k % len;
        if(k==0 || last==NULL) return head;
        
        k = len-k;
        cur = head;
        for(int i=1; i<k; ++i) cur = cur->next;
        last->next = head;
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};