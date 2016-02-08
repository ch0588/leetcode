// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //reverset from [first,last]
    ListNode* reverseList(ListNode* first, ListNode* last) {
        ListNode *pre = NULL, *now = first;
        while (now) {
            ListNode *t = now->next;
            now->next = pre;
            if (now == last) break;
            pre = now;
            now = t;
        }
        return last;
    }
public:
        ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *vRoot = new ListNode(-1); //virtual Root, it's next is head
        vRoot->next = head;

        ListNode *preLast = vRoot, *gFirst = head, *gLast = NULL, *now = head;
        int cnt = 0;
        while (now) {
            cnt++;
            if (cnt % k == 0) {
                cnt = 0;
                gLast = now;
                ListNode* nextFirst = now->next; //save next group's first node
                ListNode* t = reverseList(gFirst,gLast);
                //after reverseList,gFirst point to this group last node
                //t is this group first node after reverseList
                preLast->next = t;
                gFirst->next = nextFirst;

                preLast = gFirst;
                now = nextFirst;
                gFirst = now;
            } else {
                now = now->next;
            }
        }
        return vRoot->next;
    }

};
