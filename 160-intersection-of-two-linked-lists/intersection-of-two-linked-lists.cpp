/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        bool a = true;
        bool b = true;
        while(temp1 != temp2){
            if(!temp1->next){
                if(a){
                    temp1 = headB;
                    a = false;
                }else{
                    return NULL;
                }
            }else{
                temp1 = temp1->next;
            } 

            if(!temp2->next){
                if(b){
                    temp2 = headA;
                    b = false;
                }else{
                    return NULL;
                }
            }else{
                temp2 = temp2->next;
            }
        }
        return temp1;
    }
};