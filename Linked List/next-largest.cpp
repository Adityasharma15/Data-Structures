// 1019. Next Greater Node In Linked List

class Solution {
ListNode * reverse(ListNode * head)
{
    ListNode * prev = NULL;
    ListNode * curr = head;

    while(head!=NULL)
    {
        curr = head;
        head = head->next;
        curr->next = prev;
        prev = curr;
    }

    return curr;
}


public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int> ans;

        if(head == NULL)
            return ans;

        head = reverse(head);
        stack<int> stackk;

        while(head!=NULL)
        {
            while(!stackk.empty() && stackk.top() <= head->val)
            {
                stackk.pop();
            }

            if(stackk.empty())
             ans.push_back(0);

            else
               ans.push_back(stackk.top());

            stackk.push(head->val);
            head = head->next;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
