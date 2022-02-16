// https://leetcode.com/problems/linked-list-cycle/submissions/

// Floyd's Cycle Algorithm


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        if(head != NULL){
            while(slow && fast && fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast==slow) return true;
            }
        }
        return false;
    }
};

