// 83. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next)
            return head;

        ListNode * pos_head = head, *pos = head;
        head = head->next;

        while(head){
            if(head->val > pos->val){
                pos->next = head;
                pos = head;
            }
            head = head->next;
        }

        pos->next = NULL;
        return pos_head;
    }
};
