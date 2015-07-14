/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
解法二:设两个指针p; q，让q 先走n 步，然后p 和q 一起走，直到q 走到尾节点，删除p->next 即可。
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
