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
    int ans;
    int getAns(TreeNode *root){
        if(!root) return 0;
        int a = getAns(root->left);
        int b = getAns(root->right);
        if(a < 0 && b < 0){
            ans = max(ans, root->val);
            return root->val;
        }else if(a < 0){
            ans = max(ans, root->val + b);
            return root->val + b;
        }else if(b < 0){
            ans = max(ans, root->val + a);
            return root->val + a;
        }
        ans = max(ans, a + b + root->val);
        return max(a + root->val, b + root->val);
    }

    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        getAns(root);
        return ans;
    }
};