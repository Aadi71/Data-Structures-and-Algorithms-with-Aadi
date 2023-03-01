// https://leetcode.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0) return head;
        int n = 0;
        ListNode* node = head;
        while(node){
            n++;
            node = node -> next;
        }
        k = k % n;
        if(k == 0) return head;
        n = n - k - 1;
        node = head;
        while(n--){
            node = node -> next;
        }
        ListNode* temp = node -> next;
        ListNode* ans = temp;
        node -> next = NULL;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = head;
        return ans;
    }
};
