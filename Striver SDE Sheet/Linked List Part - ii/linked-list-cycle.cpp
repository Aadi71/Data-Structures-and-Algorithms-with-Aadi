// https://leetcode.com/problems/linked-list-cycle


// Solution without using fast and slow, using constraints.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *node = head;
        int n = 0; 
        while(n <= 10000 && node != NULL){
            n++;
            node = node -> next;
        }
        if(n > 10000) return true;
        return false;
    }
};


// Using Two Pointers, slow and fast
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(slow && fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};
