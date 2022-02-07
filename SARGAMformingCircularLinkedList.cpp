/*
Sangeet Learning Academy (SLA) started a new batch to teach SARGAM of harmonium. Several students enrolled in this batch. In the first session of SLA, instructor taught every student about SARGAM notes (sa re ga ma pa dha ni). Instructor also taught students about the different variations of SARGAM (eg. re ga ma pa dha ni sa, etc.). After the completion of the first session, instructor asked students to perform operations mentioned below on SARGAM. Create/Store SARGAM (sa re ga ma pa dha ni ) in Circular Linked List, then search for a keynote (eg. “ni”) in SARGAM (sa re ga ma pa dh ni) and

Print the SARGAM notes in ascending order (according to input keynote, here “ni”)

ni sa re ga ma pa dha ni

Print the SARGAM notes in reverse order (according to input keynote, here “ni”)

ni dha pa ma ga re sa ni

 

Program Description:

Create a function “Insert (with parameters)” to store 7 notes of SARGAM in a circular linked list. Now input a note and program will search the note in Circular Linked List using Search (with parameters) function.  Once the note is found, use “display (with parameter)” function to display the SARGAM notes in ascending as well as in reverse order (in Circular Linked List manner) starting with input provided

Note: Each input note is case sensitive: (sa and SA are different)

Input: 7 notes in new lines followed by a note of your choice

Output: Harmonium Octave for selected note followed by reverse octave.

 

Test Case 1:

Sample Input:

sa

re

ga

ma

pa

dha

ni

ni

Sample Output:

ni sa re ga ma pa dha ni

ni dha pa ma ga re sa ni
*/

#include<iostream>
#include<cstdio>
using namespace std;
struct Node {
   string word;
   struct Node *next;
};
struct Node* head = NULL;
void insert(string words){
    struct Node *newnode=(struct Node* )malloc(sizeof(struct Node));
    struct Node *ptr= head;
    newnode->word=words;
    newnode->next=head;
    if(head!=NULL){
    while(ptr->next!=head)
        ptr=ptr->next;
        ptr->next=newnode;
    }
    else
        newnode->next=newnode;
        head=newnode;
    
}
void reverse(Node** head_ref)
{
    if (*head_ref == NULL)
        return;
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != (*head_ref));
    (*head_ref)->next = prev;
    *head_ref = prev;
}
void display() {
   struct Node* ptr;
   ptr = head;
   do {
       if(ptr->next==head){
           cout<< ptr->word;
              ptr = ptr->next;
       }
       else{
      cout<< ptr->word <<" ";
      ptr = ptr->next;}
   } while(ptr != head);
}
int main()
{
    string x;
    while(cin>>x){
    insert(x);
    }
    struct Node *ptr= head;
    struct Node *ptr2=ptr->next;
    if(ptr->word==ptr2->word){
    head=head->next;
    }
    reverse(&head);
    display();
    cout<<endl;
    reverse(&head);
    display();   
}
