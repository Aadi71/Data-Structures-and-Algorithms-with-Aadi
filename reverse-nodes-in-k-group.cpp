// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        
        int c = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            c++;
        }
        
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int n = 0;
        
        while(current != NULL && n < k && c-k >= 0){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            n++;
            
        }
        c = c - k;
        if(current != NULL && c-k >= 0) head->next = reverseKGroup(next, k);
        else head -> next = next;
        
        return prev;
    }
};

//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node * current = head;
        node * prev = NULL;
        node * next = NULL;
        int t = 0;
        
        while(current != NULL && t < k){
                next = current -> next;
                current -> next = prev;
                prev = current;
                current = next;
                t++;
        }
        if(current != NULL) head -> next = reverse(next, k);
        
        return prev;
        
        
    }
};
