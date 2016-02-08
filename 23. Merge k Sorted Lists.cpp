// Time Complexity: O(n * logk)
// Space Complexity: O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct NODE{
    ListNode *node;
    NODE(ListNode* _node){
        node = _node;
    }
    bool operator<(const NODE a)const{
        return node->val > a.node->val;
    }
};
class Solution {

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<NODE> Q;
        while (!Q.empty()) Q.pop();
        int n = lists.size();

        for (int i = 0; i < n; ++i) {
            if ( !lists[i] ) continue;
            Q.push( NODE(lists[i]) );
        }
        
        ListNode *head = NULL, *pre = NULL;
        while ( !Q.empty() ) {
            NODE now = Q.top();
            Q.pop();
            if ( !head ) {
                head = now.node;
                pre = head;
            } else {
                pre->next = now.node;
                pre = now.node;
            }
            if (now.node->next) Q.push( NODE(now.node->next) );
        }
        return head;
    }
};
