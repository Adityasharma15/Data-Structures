// 25. Reverse Nodes in k-Group

class Solution {

// the idea is to traverse in windows and then do the reversal.
// let's suppose there are 4 nodes:
// A - node before the window to be reversed
// B - first node of window to be reversed
// C - last node of the window to be reversed
// D - next node of the last node of the window to be reversed

// now, we will reverse the list from B to C, and at the end,
// the next of A will point to C, and next of B will point to D.

// D can be NULL(in case len%k==0), so we will take care of that case

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode * curr = head;
        int len = 0;

        // first calculating length of the linked list
        while(curr){
            len++;
            curr = curr->next;
        }

        // we need to reverse a group of nodes only if that
        // group has nodes > size k, otherwise return the same.
        if(!head || len < k)
            return head;

        ListNode * dummy_head = new ListNode();
        dummy_head->next = head;
        ListNode * prev = dummy_head;

        // we need to iterate till the floor of len/k.
        for(int i = 0 ; i< len/k; i++){

            // acc to the explaination at the begining of the code:
            // prev will be A, head will be B
            // curr will be C, temp_next will be D
            curr = head;
            ListNode *temp_prev = prev, *temp_next ,* temp_next_next;
            for(int j = 1; j<k; j++){

               temp_next = curr->next;
               curr->next = temp_prev;
               temp_prev = curr;
               curr = temp_next;
            }

            if(curr){
            temp_next = curr->next;
            curr->next = temp_prev;
            }

            prev->next = curr;
            prev = head;
            head->next = temp_next;
            head = head->next;
        }

        return dummy_head->next;
    }
};
