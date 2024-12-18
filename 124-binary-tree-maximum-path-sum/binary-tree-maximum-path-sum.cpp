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
    long long getAns(TreeNode* root, long long &ans) {
        if(!root){
            return 0;
        }
        long long a = getAns(root->left,ans);
        long long b = getAns(root->right,ans);
        long long mx = max(a,b);
        ans = max(ans, a + b + root->val);
        if(mx <= 0){
            if(root->val < 0){
                return 0;
            }
            return root->val;
        }

        return ((long long)root->val + mx > 0) ? ((long long)root->val + mx ): 0;
    }

    int maxPathSum(TreeNode* root) {
        long long ans = INT_MIN;
        getAns(root, ans);
        return ans;
    }
};