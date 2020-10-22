// 138. Copy List with Random Pointer

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(!head)
            return NULL;

        Node *curr = head, * copy_curr = NULL;

        // create nodes of copy list with values of
        // original list
        while(curr){
            copy_curr = new Node(curr->val, curr->next, NULL);
            curr->next = copy_curr;
            curr = copy_curr->next;
        }

        // so now, next of each node of original list is pointing to
        // its duplicate in copy list and next of each node of copy
        // is pointing next element of original list

        Node * copy_head = head->next;
        curr = head;

        // now assign random pointer of the copy list
        while(curr){

            copy_curr = curr->next;
            if(curr->random){
                 copy_curr->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;

        // Now, recover the original list
        while(curr->next->next){
            copy_curr = curr->next;
            curr->next = copy_curr->next;
            copy_curr->next = copy_curr->next->next;
            curr = curr->next;
        }

        // last node of original list needs to be
        // handled differently
        curr->next = NULL;
        return copy_head;
    }
};
