/** \link https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 * \comments 基本链表操作，使用哈希表查找节点。另外下次想算法最好还是用上纸笔。。。
 *
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
        map<int,RandomListNode*> hashTable;
        RandomListNode myHead(NULL);
        RandomListNode *p,*q,*r;
        q = &myHead;
        p = head;
        while(p != NULL){
            q->next = new RandomListNode(p->label);
            q = q->next;
            p = p->next;
            hashTable.insert(pair<int,RandomListNode*>(q->label,q));
        }
        p = head;
        while(p != NULL){
            if(p->random != NULL){
                q = hashTable[p->label];
                r = hashTable[p->random->label];
                q->random = r;
            }
            p = p->next;
        }
        return myHead.next;
    }
};
