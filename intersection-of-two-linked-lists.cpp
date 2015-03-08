/** \link http://leetcode.com/problems/intersection-of-two-linked-lists/
 *comments 基本链表操作，T(n) O(1)把我吓到了，其实并不复杂
 */  
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p,*q;
        int a = 0,b = 0;
        p = headA;
        while(p != NULL){
            a++;
            p = p->next;
        }
        p = headB;
        while(p != NULL){
            b++;
            p = p->next;
        }
        int c = a - b;
        p = headA;
        q = headB;
        if(c>=0){
            while(c){
                p = p->next;
                c--;
            }
        }
        else{
            c = -c;
            while(c){
                q = q->next;
                c--;
            }
        }
        while(p != NULL){
            if(p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};
