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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = 1;
        }
        while(head && mp.find(head->val) != mp.end()){
            head = head->next;
        }
        if(head == NULL){
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while(q){
            if(mp.find(q->val) == mp.end()){
                p->next = q;
                p = q;
            }
            q = q->next;
        }
        p->next = q;
        return head;
    }
};