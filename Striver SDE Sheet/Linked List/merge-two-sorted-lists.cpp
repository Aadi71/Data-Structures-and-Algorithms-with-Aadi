// https://leetcode.com/problems/merge-two-sorted-lists/

// Iterative Solution with extra space solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                head -> next = l1;
                l1 = l1 -> next;    
            }
            else{
                head -> next = l2;
                l2 = l2 -> next;    
            }
            head = head -> next;
        }
        if(l1 != NULL) head -> next = l1;
        if(l2 != NULL) head -> next = l2;
        return temp -> next;
    }
};

// Recursive and in-place solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1 -> val > l2 -> val){
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
        else{
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }
    }
};
