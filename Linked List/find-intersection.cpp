// Intersection of Two Linked Lists
// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA ==NULL || headB== NULL)
        {
            return NULL;
        }

        unordered_set<ListNode *> sett;
        while(headA!=NULL)
        {
            sett.insert(headA);
            headA = headA->next;
        }

        for(auto i: sett)
            cout << i->val;

        while(headB!=NULL)
        {
            if(sett.count(headB) >0)
                return headB;

            headB = headB->next;
        }

        return NULL;

    }
};
