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
    int getAns(TreeNode *root, int &ans){
        if(!root) return 0;
        int a = getAns(root->left, ans);
        int b = getAns(root->right, ans);
        int sum = max(a + root->val, max(root->val, b + root->val));
        ans = max(ans, max(sum, root->val + a + b));
        return sum;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getAns(root, ans);
        return ans;
    }
};