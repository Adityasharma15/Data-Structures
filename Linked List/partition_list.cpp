// 86. Partition List

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode *smaller = new ListNode();
        ListNode *greater = new ListNode();
        ListNode *first = smaller, *second = greater;

        while(head){

            if(head->val < x){
              ListNode * temp = new ListNode(head->val);
              smaller->next = temp;
              smaller = smaller->next;

            } else{
              ListNode * temp = new ListNode(head->val);
              greater->next = temp;
              greater = greater->next;
            }

            head = head->next;
        }

        if(smaller){
            smaller->next = second->next;
        }

        return first->next;
    }
};
