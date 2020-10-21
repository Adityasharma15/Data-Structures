// 143. Reorder List

class Solution {

// the idea is to reverse the second half of the array and combine
// nodes alternatively of first half of the original list and the
// reversed second half of the original list.

public:
    void reorderList(ListNode* head) {

        if(!head)
            return;

        // FINDING THE MID ELEMENT
        ListNode * slow = head, * fast = head;
        while(fast->next!= NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        // REVERSING THE SECOND HALF OF LIST
        ListNode * second_head = slow->next;
        slow->next = NULL;
        ListNode * curr = second_head, * prev = NULL;
        while(curr){
            second_head = second_head->next;
            curr->next = prev;
            prev = curr;
            curr = second_head;
        }

        // COMBINING NODES ALTERNATIVELY of both lists

        second_head = prev;
        ListNode * head_next, *second_head_next;

        // head_next stores next node of the first list and
        // second_head_temp stores the next node of reversed list
        while(head && second_head){
            head_next = head->next;
            // combining first node of first list to the
            // first node of second(reversed) list
            head->next = second_head;
            second_head_next = second_head->next;

            // next point of first node of second(reversed)
            // pointing to the second element of first list
            second_head->next = head_next;

            // both pointers move to the other node of their list
            second_head = second_head_next;
            head = head_next;
        }
        return;
    }
};
