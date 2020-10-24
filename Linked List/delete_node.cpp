// 237. Delete Node in a Linked List

class Solution {
public:
    void deleteNode(ListNode* node) {

        if(!node)
            return;

        // no way to delete if it is tail, so as given
        // in que, assume its not the tail

        // give it the value of next node, obviously
        // its value is lost, then point to the next
        // of the next node so connection to next
        // node is lost, but we do have value of next
        // so value of this node is lost
        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};
