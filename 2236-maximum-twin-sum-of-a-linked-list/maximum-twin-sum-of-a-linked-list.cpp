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
    int pairSum(ListNode* head) {
        int mx = 0;
        int n = 0;
        ListNode *h = head;
        while(h){
            n += 2;
            h = h->next->next;
        }
        vector<int> nums(n/2, 0);
        h = head;
        int curr = 0;
        while(h){
            if(curr < n/2){
                nums[curr] = h->val;
            }else{
                mx = max(mx, nums[n - curr - 1] + h->val);
            }   
            curr++;
            h = h->next;
        }
        return mx;
    }
};

// 0 1 2 3

// 4 - 2 - 1 = 1
// 4 -3 - 1 = 0