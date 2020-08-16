// Remove duplicates from an unsorted linked list

Node * removeDuplicates( Node *head)
{

 if(head == NULL)
    return head;

 Node * last = head;
 Node * curr = head->next;
 unordered_set<int> sett;
 sett.insert(head->data);

 while(curr!= NULL)
 {
     if(sett.count(curr->data) == 0)
     {
        last->next = curr;
        last = curr;
     }

     sett.insert(curr->data);
     curr = curr->next;
 }

 last->next = NULL;
 return head;
}
