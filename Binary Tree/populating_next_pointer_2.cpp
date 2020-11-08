// 117. Populating Next Right Pointers in Each Node II

class Solution {

// Popluate next pointer of the lower level by traversing current level using
// the already populated next pointers

public:
    Node* connect(Node* root) {

        Node * head = root;

        // traversing to next level
        while(head){

            // first is first node in this level
            Node *first = NULL, *curr = NULL;

            // traversing within the current level
            while(head){

                if(head->left){

                  if(curr){
                      curr->next = head->left;
                      curr = curr->next;

                  }  else{
                      curr = head->left;
                      first = curr;
                  }
                }

                if(head->right){

                    if(curr){
                        curr->next = head->right;
                        curr = curr->next;

                    } else{
                        curr = head->right;
                        first = curr;
                    }

                }

                head = head->next;
            }

            head = first;
        }

        return root;
    }
};
