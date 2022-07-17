// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* main = new ListNode(0);
        ListNode* ret = main;
        int carry = 0;
        int sum;
        while(l1 || l2 || carry){
            sum = (l1 != NULL ? l1 -> val : 0) + (l2 != NULL ? l2 -> val : 0) + carry;
            carry = sum / 10;
            main -> next = new ListNode(sum % 10);
            l1 = l1 != NULL ? l1 -> next : l1;
            l2 = l2 != NULL ? l2 -> next : l2;
            main = main -> next;
        }
        
        
        // while(l1 != NULL && l2 != NULL){
        //     sum = carry + l1 -> val + l2 -> val;
        //     carry = sum / 10;
        //     sum = sum % 10;
        //     main -> next = new ListNode(sum);
        //     main = main -> next;
        //     l1 = l1 -> next;
        //     l2 = l2 -> next;
        // }
        // while(l1){
        //     sum = carry + l1 -> val;
        //     carry = sum / 10;
        //     sum = sum % 10;
        //     main -> next = new ListNode(sum);
        //     main = main -> next;
        //     l1 = l1 -> next;
        // }
        // while(l2){
        //     sum = carry + l2 -> val;
        //     carry = sum / 10;
        //     sum = sum % 10;
        //     main -> next = new ListNode(sum);
        //     main = main -> next;
        //     l2 = l2 -> next;
        // }
        // while(carry > 0){
        //     sum = carry % 10;
        //     main -> next = new ListNode(sum);
        //     main = main -> next;
        //     carry /= 10; 
        // }
        return ret -> next;
    }
};
