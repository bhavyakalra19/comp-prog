/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getAns(vector<int> nums){
        int n = nums.size();
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({nums[i],i});
        }
        sort(check.begin(),check.end());
        vector<bool> visit(n,false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int idx = i;
            if(check[idx].second != idx && !visit[idx]){
                visit[i] = true;
                while(!visit[check[idx].second]){
                    idx = check[idx].second;
                    visit[idx] = true;
                    ans++;
                }
            }
        }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> nums;
            while(size--){
                auto it = q.front();
                q.pop();
                if(it->left){
                    nums.push_back(it->left->val);
                    q.push(it->left);
                }
                if(it->right){
                    nums.push_back(it->right->val);
                    q.push(it->right);
                }
            }
            ans += getAns(nums);
        }
        return ans;
    }
};
