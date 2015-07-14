/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
�ⷨ��:������ָ��p; q����q ����n ����Ȼ��p ��q һ���ߣ�ֱ��q �ߵ�β�ڵ㣬ɾ��p->next ���ɡ�
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL || n<1) return head;

        ListNode *fa = new ListNode(-1);
        fa->next = head;
        ListNode *pre = fa, *cur = head;

        int len = 0;
        while(cur){
            len++; cur=cur->next;
        }
        if(n>len) return head;
        n = len-n+1;

        pre=fa; cur = head;
        for(int i=1; i<n; ++i){
            if(cur==NULL) return head;
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return fa->next;
    }
};
