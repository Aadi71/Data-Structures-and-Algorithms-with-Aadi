// https://leetcode.com/problems/partition-list/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
      // Single Pointer Approach:
      
        // ListNode* main = new ListNode(0);
        // ListNode* result = main;
        // ListNode* temp = head;
        // while(temp){
        //     if(temp -> val < x){
        //         main -> next = new ListNode(temp -> val);
        //         main = main -> next;
        //     }
        //     temp = temp -> next;
        // }
        // temp = head;
        // while(temp){
        //     if(temp -> val >= x){
        //         main -> next = new ListNode(temp -> val);
        //         main = main -> next;
        //     }
        //     temp = temp -> next;
        // }
        // return result -> next;
        
      
      // Double Pointer Approach
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);
        ListNode* l1 = p1;
        ListNode* l2 = p2;
        
        while(head){
            if(head -> val < x) p1 = p1 -> next = head;
            else p2 = p2 -> next = head;
            head = head -> next;
        }
        p2 -> next = NULL;
        p1 -> next = l2 -> next;
        return l1 -> next;
    }
};
