// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* root = new ListNode(-1);
        ListNode* head = root;
        int sum;
        while(l1 || l2 || carry){
            sum = (l1 != NULL ? l1 -> val : 0) + carry + (l2 != NULL ? l2 -> val : 0);
            carry = sum / 10;
            root -> next = new ListNode(sum % 10);
            root = root -> next;
            l1 = l1 != NULL ? l1 -> next : l1;
            l2 = l2 != NULL ? l2 -> next : l2;
        }
        return head -> next;
    }
};
