// Odd Even Linked List

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

       if(head == NULL)
            return head;

        ListNode * new_head = head;
        ListNode * second_head = head->next;
        ListNode * odd = head;
        ListNode * even = head->next;

        while(odd->next!= NULL && even->next!=NULL)
        {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = second_head;

        return new_head;
    }
};
