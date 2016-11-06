/*
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
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
    ListNode* plusOne(ListNode* head) {
    if(!head)
    return head;
    
        int carry =  help(head);
        if(carry == 1){
            ListNode* newone = new ListNode(carry);
            newone->next = head;
            return newone;
        }else{
            return head;
        }
        
    }
    //return the carry
    int help(ListNode* head){
        int num;
        if(head->next==NULL){
            //reach end;
            num = head->val + 1;
        }else{
            num = head->val+help(head->next);
        }
        if(num<10){
            head->val = num;
            return 0;
        }else{
            head->val = 0;
            return 1;
        }
    }
};
