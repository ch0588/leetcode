#include<stdio.h>
#include<string.h>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(head==NULL || head->next==NULL) return head;

        ListNode *newHead = new ListNode(0);
        ListNode * pre = newHead;
        pre->next = head;
        ListNode *cur = head;

        while(cur!=NULL)
        {
            while(cur->next!=NULL && pre->next->val==cur->next->val) cur = cur->next;
            if(pre->next==cur)
            {
                pre = pre->next;
            }
            else
            {
                //printf("OK");
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return newHead->next;
    }
//ListNode *deleteDuplicates(ListNode *head)
//{
//    if(head == NULL)
//        return head;
//    ListNode *helper = new ListNode(0);
//    helper->next = head;
//    ListNode *pre = helper;
//    ListNode *cur = head;
//    while(cur!=NULL)
//    {
//        while(cur.next!=NULL && pre.next.val==cur.next.val)
//        {
//            cur = cur.next;
//        }
//        if(pre.next==cur)
//        {
//            pre = pre.next;
//        }
//        else
//        {
//            pre.next = cur.next;
//        }
//        cur = cur.next;
//    }
//
//    return helper.next;
int main()
{
    ListNode *head = new ListNode(1);
    ListNode *p = new ListNode(2);
    head->next = p;
    ListNode *q = new ListNode(2);
    p->next = q;

    head = deleteDuplicates(head);
    while(head!=NULL)
    {
        printf("%d\n",head->val);
        head = head->next;
    }
    return 0;
}
