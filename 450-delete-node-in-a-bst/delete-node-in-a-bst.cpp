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
    int getLeftMost(TreeNode *temp){
        while(temp->left){
            temp = temp->left;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val == key){
            if(!root->left){
                return root->right;
            }else if(!root->right){
                return root->left;
            }else{
                root->val = getLeftMost(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};