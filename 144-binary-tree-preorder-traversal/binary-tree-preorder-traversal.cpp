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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> q;
        while(root || !q.empty()){
            if(!root){
                root = q.top();
                q.pop();
            }
            output.push_back(root->val);
            if(root->left){   
                if(root->right){
                    cout << root->right->val << endl;
                    q.push(root->right);
                }
                root = root->left;
            }else if(root->right){
                root = root->right;
            }else{
                root = NULL;
            }
        }
        return output;
    }
};