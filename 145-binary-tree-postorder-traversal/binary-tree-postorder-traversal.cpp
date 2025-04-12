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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                if(root->right) st.push(root);
                root = root->left;
            }else{
                root = st.top();
                st.pop();
                if(st.empty() || st.top() != root){
                    ans.push_back(root->val);
                    root = NULL;
                }else{
                    root = root->right;
                }
            }
        }
        return ans;
    }
};