// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        Node* temp = NULL, *ptr = head;
        unordered_set<int> check;
        while(ptr != NULL){
            if(check.find(ptr -> data) != check.end()){
                temp -> next = ptr -> next;
                delete(ptr);
            }
            else{
                check.insert(ptr -> data);
                temp = ptr;
            }
            ptr = temp -> next;
        }
        return head;
    }
};
