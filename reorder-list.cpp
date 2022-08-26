// https://leetcode.com/problems/reorder-list/


class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* newHead = NULL;
        
        while(head != NULL){
            ListNode* next = head -> next;
            head -> next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode* mid = middle(head);
        ListNode* right = reverse(mid), *left = head -> next;
        for(int i = 0; left != right; i++, head = head -> next){    // re-order in alternating fashion 
            if(i & 1) {                              
                head -> next = left;
                left = left -> next;
            }
            else {
                head -> next = right;
                right = right -> next;
            }
        }
    } 
};
