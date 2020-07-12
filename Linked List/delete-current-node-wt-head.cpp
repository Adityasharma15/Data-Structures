// Delete without head pointer
// https://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/


void deleteNode(Node *node)
{
   while(node->next!=NULL)
   {
        if(node->next->next == NULL)
        {
            int temp1 = node->next->data;
            node->data = temp1;
            node->next = NULL;
            break;
        }

        int temp = node->next->data;
        node->data = temp;
        node = node->next;
   }
}
