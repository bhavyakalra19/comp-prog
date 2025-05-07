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
    int moves;
    int getAns(TreeNode *root){
        if(!root){
            return 0;
        }
        int a = getAns(root->left);
        int b = getAns(root->right);
        moves += abs(a) + abs(b);
        return a + b - 1 + root->val;
    }

    int distributeCoins(TreeNode* root) {
        moves = 0;
        getAns(root);
        return moves;
    }
};