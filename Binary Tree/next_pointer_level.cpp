// 116. Populating Next Right Pointers in Each Node

class Solution {
public:
    Node* connect(Node* root) {

        if(!root)
          return root;

        Node * level_first_node = root;

        // getting through to the next level
        while(level_first_node->left){

           Node * level_next_node = level_first_node;

            // traversing through this level
            while(level_next_node){

            // remember we are making changes to the lower level to the
            // level_next_node, next pointers of the same level of
            // level_next_node has previously assigned by the last loop

            // if this node has 2 children, left one will point to right one
            if(level_next_node->left){
                level_next_node->left->next = level_next_node->right;
            }

            // now we are moving out of the childs of level_next_node,
            // but we know level_next_node has its next assigned, we will use
            // this to find what level_next_node->right->next should be assigned to
            if(level_next_node->right){

                if(level_next_node->next){
                        level_next_node->right->next = level_next_node->next->left   ;
                } else{
                    level_next_node->right->next = NULL;
                }
            }

            // traversing through the current level of the tree using the
            // right pointer we previously assigned
            level_next_node = level_next_node->next;
           }

            // traversing through the next level, this is only possible
            // because the given tree is a perfect binary tree
            level_first_node = level_first_node->left;
        }

        return root;
    }
};
