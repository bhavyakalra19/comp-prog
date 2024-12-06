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
    int getAns(TreeNode *root, int ch){
        if(!root){
            return 0;
        }
        int a = getAns(root->left, max(ch,root->val));
        int b = getAns(root->right, max(ch,root->val));
        return a + b + (root->val >= ch ? 1 : 0);
    }

    int goodNodes(TreeNode* root) {
        return getAns(root,INT_MIN);
    }
};