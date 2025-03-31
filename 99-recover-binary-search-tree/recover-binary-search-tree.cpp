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
    TreeNode *temp1;
    TreeNode *temp2;
    TreeNode *prev;

    void getAns(TreeNode *root){
        if(!root) return;
        getAns(root->left);
        if(temp1 == NULL && prev->val > root->val){
            temp1 = prev;
            temp2 = root;
        }else if(temp1 != NULL && prev->val > root->val){
            temp2 = root;
        }
        prev = root;
        getAns(root->right);
    }

    void recoverTree(TreeNode* root) {
        temp1 = NULL;
        temp2 = NULL;
        prev = new TreeNode(INT_MIN);
        getAns(root);
        int a = temp1->val;
        temp1->val = temp2->val;
        temp2->val = a;
    }
};