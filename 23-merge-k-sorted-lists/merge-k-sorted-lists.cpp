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
        int n = lists.size();
        ListNode *temp = NULL;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i= 0; i < n; i++){
            if(lists[i]){
                pq.push({lists[i]->val, i});
            }
        }
        if(pq.empty()){
            return temp;
        }
        auto it = pq.top();
        pq.pop();
        temp = lists[it.second];
        lists[it.second] = lists[it.second]->next;
        if(lists[it.second] != NULL){
            pq.push({lists[it.second]->val,it.second});
        }
        ListNode *head = temp;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            temp->next = lists[it.second];
            temp = temp->next;
            lists[it.second] = lists[it.second]->next;
            if(lists[it.second] != NULL){
                pq.push({lists[it.second]->val,it.second});
            }
        }
        return head;
    }
};