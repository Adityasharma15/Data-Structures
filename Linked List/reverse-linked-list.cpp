// Reverse a linked list
// https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

            ListNode * curr = head;
            ListNode * prev = NULL;

            while(head!=NULL)
            {
                curr = head;
                head = head->next;
                curr->next = prev;
                prev = curr;
            }

            return curr;
    }
};
