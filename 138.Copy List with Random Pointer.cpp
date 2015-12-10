/*
分为三步
1. 插入拷贝节点
2. 复制random指针
3.分解至两个独立列表
http://fisherlei.blogspot.tw/2013/11/leetcode-copy-list-with-random-pointer.html
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *cur = head;
        
        //insert new node into each node
        while(cur!=NULL){
            RandomListNode *t = new RandomListNode(cur->label);
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }
        
        //copy random
        cur = head;
        while(cur!=NULL){
            RandomListNode *t = cur->next;
            if(cur->random != NULL)
                t->random = cur->random->next;
            cur = t->next;
        }
        
        //split two links
        cur = head;
        RandomListNode* rHead = head == NULL? NULL:head->next;
        while(cur!=NULL){
            RandomListNode* t = cur->next;
            cur->next = t->next;
            if(t->next!=NULL)
                t->next = t->next->next;
            cur = cur->next;
        }
        return rHead;
    }
};