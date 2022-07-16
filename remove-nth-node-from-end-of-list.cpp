// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = new ListNode(0);
        node -> next = head;
        ListNode* l = node;
        ListNode* r = head;
        while(n--){
            r = r -> next;
        }
        while(r){
            l = l -> next;
            r = r -> next;
        }
        l -> next = l -> next -> next;
        return node -> next;
    }
};
