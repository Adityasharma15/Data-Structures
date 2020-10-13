234. Palindrome Linked List

class Solution{
// reverse from mid

    ListNode * reverse(ListNode * head){
        ListNode * curr = head, * prev = NULL;

        while(head){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
          return true;

        ListNode * slow = head, * fast = head;

        // find the mid of list using slow & fast
        // pointers
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // now reverse the other half of the list
        // and compare starting from head
        slow = reverse(slow->next);
        while(slow && head){

            if(slow->val != head->val)
                return false;

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};
