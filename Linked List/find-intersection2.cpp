// 160. Intersection of Two Linked Lists

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(!headA || !headB)
            return NULL;

        int len1 = 0, len2 = 0;

        ListNode* temp = headA;
        while(temp){
            len1++;
            temp = temp->next;
        }

        temp = headB;
        while(temp){
            len2++;
            temp=temp->next;
        }

        while(headA && headB){

            if(headA == headB)
                return headA;

            if(len1 > len2){
                headA = headA->next;
                len1--;
                continue;
            }

            if(len1 < len2){
                headB = headB->next;
                len2--;
                continue;
            }

            headA = headA->next;
            headB = headB->next;
            len1--; len2--;
        }

        return NULL;
    }
};
