// 92. Reverse Linked List II

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        // pos is to keep a count of position and rev will be the head
        // of the reversed linked list.
        // prev is pointing to the node after which the list needs to be
        // reversed
        int pos = 1;
        ListNode * rev = head;
        ListNode * curr = head;
        ListNode * prev = NULL;

        // if m and n are equal then nothing needs to be done
        if(m==n)
            return rev;

        // this is done to reach to the first node that needs to be reversed
        while(pos<m){
            prev = head;
            head=head->next;
            pos++;
        }

        // start_rev points to the start of the part of the list that needs
        // to be reversed, end_rev points to the end of the part that needs
        // to be reversed. head & curr will currently point to the second
        // node of the list to be reversed.
        ListNode * start_rev = head;
        ListNode * end_rev = head;
        head = head->next;
        curr = head;
        pos++;

        while(pos<=n){
            // head moves to the next node in the list because we will
            // change the next of the node head is pointing currently to the
            // previous node of this list.
             head = head->next;

            // we change the next of this node we are visiting, head is alread
            // pointing to the next node of this list that needs to be
            // reversed.
             curr->next = end_rev;

            // updating end of the list being reversed
             end_rev = curr;
             curr = head;
             pos++;
        }

        // the start of the part of the list that is reversed now needs to             // point to the node next to the end of this list that is reversed
        start_rev->next = head;

        // if the node previous to start_rev, which is prev, exists, then
        // end of reversed list needs to point to it, otherwise end_rev will
        // be the begining of the whole list.
        if(prev)
            prev->next = end_rev;

        else
            rev = end_rev;

        return rev;
    }
};
