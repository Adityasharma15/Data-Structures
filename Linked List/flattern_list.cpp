// 430. Flatten a Multilevel Doubly Linked List

class Solution{

// will be using a stack based approach
public:
    Node* flatten(Node* head) {

        if(!head)
            return NULL;

        Node * prev = NULL, * curr = NULL;
        stack<Node * > stck;
        stck.push(head);

        // the approach is to just to operate a single node at
        // a time, correct the node by removing child, and
        // assigning correct next and putting it into the
        // list correctly, and then push it next and childs
        // to be considered later, we push child later because child
        // needs to be operated earlier

        while(!stck.empty()){

            curr = stck.top();
            stck.pop();

            // these nodes will be covered later, the
            // later depends upon the size list associated
            // with the child of this node.
            if(curr->next) stck.push(curr->next);
            if(curr->child) stck.push(curr->child);

            // correctly allocating this node to list
            curr->child = NULL;
            curr->prev = prev;
            if(prev) prev->next = curr;
            prev = curr;
        }

        return head;
    }
};
