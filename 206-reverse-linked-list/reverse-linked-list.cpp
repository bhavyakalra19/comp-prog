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
    ListNode *ans;
    ListNode* getAns(ListNode *head){
        if(!head->next){
            ans = head;
            return head;
        }
        ListNode *t = getAns(head->next);
        t->next = head;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *temp = getAns(head);
        temp->next = NULL;
        return ans;
    }
};