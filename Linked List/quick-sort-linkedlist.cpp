// Quick Sort Linked List

class Solution {

ListNode * partition(ListNode * left, ListNode * right)
{
    if(left == right || !left || !right)
        return NULL;

    // in LL we take first element as pivot
    ListNode * pivot = left;
    ListNode * ptr = left;
    left = left->next;

    // right->next bcoz we need to consider last element as well
    // which is right;
    while(left!=right->next)
    {
        if(left->val < pivot->val)
        {
            ptr = ptr->next;
            int temp = left->val;
            left->val = ptr->val;
            ptr->val = temp;
        }

        left = left->next;
    }

        // replacing pivot with last element found to be smaller
        // than pivot;
        int temp = ptr->val;
        ptr->val = pivot->val;
        pivot->val = temp;

    return ptr;
}

void quickSortUtil(ListNode * head, ListNode * tail)
{
    if(head == tail || !head || !tail)
        return;

    ListNode * mid = partition(head, tail);

    quickSortUtil(head, mid);
    quickSortUtil(mid->next, tail);
}


public:
    ListNode* sortList(ListNode* head) {
    ListNode * tail = head;
    if(!head) return NULL;

    while(tail->next) tail = tail->next;

    quickSortUtil(head, tail);
    return head;
    }
};
