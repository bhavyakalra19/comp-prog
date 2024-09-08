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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        vector<ListNode*> ans;
        while(p){
            n += 1;
            p = p->next;
        }
        int ex = n % k;
        p = head;
        while(p){
            int a = 0;
            int t = n / k;
            if(ex > 0){
                t += 1;
                ex -= 1;
            }
            ListNode *q = p;
            ListNode *temp = q;
            while(p && a < t){
                q = p;
                p = p->next;
                a += 1;
            }
            q->next = NULL;
            ans.push_back(temp);
        }
        n = ans.size();
        while(n < k){
            ans.push_back(NULL);
            n++;
        }
        return ans;
    }
};