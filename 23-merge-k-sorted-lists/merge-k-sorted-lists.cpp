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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            if(lists[i] != NULL) pq.push({lists[i]->val, lists[i]});
        }
        ListNode *temp = new ListNode(-1);
        ListNode *head = temp;
        while(!pq.empty()){
            ListNode *n = pq.top().second;
            pq.pop();
            temp->next = n;
            temp = temp->next;
            if(n->next) pq.push({n->next->val, n->next});
        }
        return head->next;
    }
};