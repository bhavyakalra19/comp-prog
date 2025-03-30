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
        stack<TreeNode*> st;
        vector<int> ans;
        while(root || !st.empty()){
            if(root){
                ans.push_back(root->val);
                if(root->left) st.push(root->left);
                root = root->right;
            }else{
                root = st.top();
                st.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};