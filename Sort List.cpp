/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 版本1快速排序，需要加入剪枝，如果一个序列所有数相等，则不需要递归
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL) return head;
        ListNode *lRoot = new ListNode(-1);
        ListNode *rRoot = new ListNode(-1);
        ListNode *piot = head;

        ListNode *lp = lRoot,*rp = rRoot;
        ListNode *lastLeft = NULL;
        int minL=INT_MAX,minR=INT_MAX,maxL=INT_MIN,maxR=INT_MIN;
        head = head->next;
        while(head!=NULL){
            if(head->val <= piot->val){
                minL = min(minL,head->val);
                maxL = max(maxL,head->val);
                lp->next = head;
                lp = lp->next;
                head = head->next;
                lp->next = NULL;
            }
            else{
                minR = min(minR,head->val);
                maxR = max(maxR,head->val);
                rp->next = head;
                rp = rp->next;
                head = head->next;
                rp->next = NULL;
            }
        }
        if(minL==maxL)
            lp = lRoot->next;
        else
            lp = sortList(lRoot->next);

        if(minR==maxR)
            rp = rRoot->next;
        else
            rp = sortList(rRoot->next);

        lastLeft = lp;
        while(lastLeft!=NULL && lastLeft->next!=NULL) lastLeft = lastLeft->next;

        //merge
        if(lp==NULL){
            piot->next = rp;
            return piot;
        }
        else{
            lastLeft->next = piot;
            piot->next = rp;
            return lp;
        }
    }
};

 /*
 版本2归并排序
 */
class Solution {
public:
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        ListNode *vRoot = new ListNode(-1), *cur = vRoot;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while(l1!=NULL){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2!=NULL){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        cur->next = NULL;

        cur = vRoot->next;
        return cur;
    }
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL) return head;

        int cnt = 0;
        ListNode *mid,*cur,*l1,*l2;
        cur = head;
        while(cur!=NULL){
            cnt++;
            cur = cur->next;
        }
        mid = head;
        for(int i=1; i<cnt/2; ++i) mid = mid->next;

        cur = mid; mid = mid->next; cur->next = NULL;
        l1 = sortList(head);
        l2 = sortList(mid);
        head = mergeList(l1,l2);
        return head;
    }
};
