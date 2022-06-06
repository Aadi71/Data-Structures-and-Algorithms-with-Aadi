// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        int l1 = 0, l2 = 0;
        while(ptr1 -> next) {
            ptr1 = ptr1->next;
            l1 += 1;
        }
        while(ptr2 -> next){
            ptr2 = ptr2->next;
            l2 += 1;   
        }
        
        if(l1 > l2){
            int l = l1 - l2;
            while(l--){
                headA = headA -> next;
            }
        }
        else{
            int l = l2 - l1;
            while(l--){
                headB = headB-> next;
            }
        }
        
        while(headA || headB){
            if(headA == headB) return headA;
            else{
                headA = headA -> next;
                headB = headB -> next;
            }
            
        }
        return NULL;
    }
};
