// Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0, num = 0;
        ListNode * head = NULL;
        ListNode * first_head = NULL;

        while(l1!=NULL || l2!=NULL)
        {
            int a = (l1!=NULL)? l1->val : 0;
            int b = (l2!=NULL)? l2->val : 0;

            num = a + b + carry;

            carry = num;
            carry /=10;
            num %= 10;

            ListNode * temp = new ListNode(num, NULL);

            if(head == NULL)
            {
                head = temp;
                first_head = head;
            }
            else
            {
                head->next = temp;
                head = head->next;
            }

            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }

        if(carry == 0)
            return first_head;

        if(head == NULL)
            head = new ListNode(carry, NULL);

        else
            head->next = new ListNode(carry, NULL);

        return first_head;
    }
};
