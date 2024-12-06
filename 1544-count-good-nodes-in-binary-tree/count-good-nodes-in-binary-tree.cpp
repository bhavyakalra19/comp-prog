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
    void getAns(TreeNode *root, int &ans, int ch){
        if(!root){
            return;
        }
        if(root->val >= ch){
            ans += 1;
        }
        getAns(root->left, ans, max(ch,root->val));
        getAns(root->right, ans, max(ch,root->val));
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        getAns(root,ans,INT_MIN);
        return ans;
    }
};