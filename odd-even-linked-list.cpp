// https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);
        ListNode *l1 = p1;
        ListNode *l2 = p2;
        
        while(head){
            p1 = p1 -> next = head = head -> next;
            head = head -> next;
            if(!head) break;
            p2 = p2 -> next = head;
            head = head -> next;
        }
        p1 -> next = l2 -> next;
        p2 -> next = NULL;
        return l1 -> next;
    }
};
