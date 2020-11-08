// 141. Linked List Cycle

class Solution {

// Brute solution can be using a hash map
public:
    bool hasCycle(ListNode *head) {

        if(!head)
            return true;

        ListNode *slow = head, *fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
                return true;
        }

        return false;
    }
};
