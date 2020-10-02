// Reverse a linked list
// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

            ListNode * curr = head;
            ListNode * prev = NULL;

            while(head!=NULL){
            // head moves to the next node in the list because we will
            // change the next of the node head is pointing currently to the
            // previous node of this list.
                curr = head;
                head = head->next;
                
            // we change the next of this node we are visiting, head is alread
            // pointing to the next node of this list that needs to be 
            // reversed.     
                curr->next = prev;
                prev = curr;
            }

            return curr;
    }
};
