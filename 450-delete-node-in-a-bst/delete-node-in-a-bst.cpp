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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }
        if(root->val == key){
            if(!root->left && !root->right){
                return NULL;
            }else if(!root->left){
                return root->right;
            }else if(!root->right){
                return root->left;
            }else{
                TreeNode *temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        }else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};