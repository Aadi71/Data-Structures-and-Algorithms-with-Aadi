// https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b){
            a = a == NULL ? headB : a -> next;
            b = b == NULL ? headA : b -> next;
        }
        return a;
    }
};  
