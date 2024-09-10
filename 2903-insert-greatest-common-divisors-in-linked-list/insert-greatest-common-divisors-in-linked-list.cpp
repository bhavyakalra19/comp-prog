/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getAns(int a, int b){ 
        // Everything divides 0 
        if (a == 0) 
            return b; 
        if (b == 0) 
            return a; 
        if (a == b) 
            return a;  
        if (a > b) 
            return gcd(a - b, b); 
        return gcd(a, b - a); 
    } 

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while(q){
            ListNode *temp = new ListNode(getAns(p->val,q->val));
            p->next = temp;
            temp->next = q;
            p = q;
            q = q->next;
        }
        return head;
    }
};