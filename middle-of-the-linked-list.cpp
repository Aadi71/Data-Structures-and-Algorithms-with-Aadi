// https://leetcode.com/problems/middle-of-the-linked-list/submissions/

// Method 1: 
// Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while(temp){
            c++;
            temp = temp -> next;
        }
        if(c % 2 == 0) c = c / 2;
        else c = c / 2;
        
        while(c){
            c--;
            head = head -> next;
        }
    return head;
    }
};

// Method 2: 
// Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.

class Solution {
public:
    ListNode* slow = head;
        ListNode* fast = head;
        
        if(head != NULL){
            while(fast != NULL && fast->next != NULL){
                fast = fast -> next -> next;
                slow = slow -> next;
            }
        }
        return slow;
    }
};


// Method 3: 
// Initialize mid element as head and initialize a counter as 0. Traverse the list from head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. So the mid will move only half of the total length of the list. 


class Solution {
public:
    int count = 0;
    ListNode* mid = head;
 
    while (head != NULL)
    {
         
        // Update mid, when 'count'
        // is odd number
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    if (mid != NULL)
        return mid;
    return mid;
    }
};
