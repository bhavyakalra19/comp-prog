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
    void getAns(TreeNode *root, vector<int> &check){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            check.push_back(root->val);
        }
        getAns(root->left,check);
        getAns(root->right,check);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> check1;
        vector<int> check2;
        getAns(root1,check1);
        getAns(root2,check2);
        return check1 == check2;
    }
};