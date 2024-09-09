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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<vector<bool>> check(m,vector<bool>(n,false));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int idx = 0;
        int nx;
        int ny;
        int x = 0;
        int y = 0;
        ans[0][0] = head->val;
        head = head->next;
        check[0][0] = true;
        while(head){
            nx = x + dx[idx];
            ny = y + dy[idx];
            if(nx < m && nx >= 0 && ny < n && ny >= 0 && check[nx][ny] == false){
                ans[nx][ny] = head->val;
                head = head->next;
                check[nx][ny] = true;
                x = nx;
                y = ny;
            }else{
                idx += 1;
                idx = idx % 4;
            }
        }
        return ans;
    }
};