// https://leetcode.com/problems/rotate-list/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;
        
        int length = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            ptr = ptr -> next;
            length++;
        }
        k = k % length;
      
        if(k == 0) return head;
      
        k = length - k - 1;
        ptr = head;
        while(k--){
            ptr = ptr -> next;
        }
        ListNode* temp = ptr;
        ptr = ptr -> next;
        ListNode* new_head = ptr;
        while(ptr -> next != NULL) ptr = ptr -> next;
        ptr -> next = head;
        
        temp -> next = NULL;
        head = new_head;
        return head;
        
    }
};
