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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *main = root;
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        for(int i = 1; i < n; i++){
            TreeNode *temp = new TreeNode(preorder[i]);
            while(!st.empty() && mp[st.top()->val] < mp[preorder[i]]){
                root = st.top();
                st.pop();
            }
            if(mp[root->val] > mp[preorder[i]]){
                root->left = temp;
            }else{
                root->right = temp;
            }
            root = temp;
            st.push(temp);
        }
        return main;
    }
};