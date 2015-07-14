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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *p1 = head;
        ListNode *p2 = head;
        bool isCircle = false;
        while(p2!=NULL && p2->next!=NULL){
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1==p2) {
                isCircle = true;
                break;
            }
        }
        if(!isCircle) return NULL;

        p1 = head;
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
